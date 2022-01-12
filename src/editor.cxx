// Copyright 2017-2018, 2020 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, 
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this 
//	list of conditions and the following disclaimer in the documentation and/or 
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may 
//	be used to endorse or promote products derived from this software 
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <QSettings>
#include <QTextDocument>
#include <QFontMetrics>
#include <QFont>
#include <QTextCursor>
#include <QVariant>

#include <editor.hpp>
#include <global.hpp>
#include <window.hpp>
#include <main_toolbar.hpp>
#include <menus/editor_context.hpp>

bool Editor::autoindent = true;
QString Editor::colorID = "#d9d9d9";

void Editor::updateSettings() {
    Editor::autoindent = settings.value("editor/autoindent","true").toBool();
    Editor::colorID = settings.value("editor/line_color","#d9d9d9").toString();
}

Editor::Editor(QString path, Window *parent)
    : layout(new QVBoxLayout),
      editor(new TextEdit(this)),
      finder(new Finder(this))
{
    this->parent = parent;
    filePath = path;

    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);
    layout->addWidget(editor);
    layout->addWidget(finder,0,Qt::AlignBottom);

    connect(editor,&QTextEdit::textChanged,this,&Editor::onModified);
    connect(editor,&QTextEdit::cursorPositionChanged,this,&Editor::highlightCurrentLine);

    QTextDocument *doc = new QTextDocument();
    editor->setDocument(doc);
    
    highlight = new QSourceHighliter(doc);

    updateFont();
    updateTabWidth();

    finder->hide();
}

TextEdit *Editor::editorWidget() {
    return editor;
}

void Editor::updateFont() {
    QString fontStr = settings.value("editor/font").toString();
    int fontSize = settings.value("editor/font_size", 12).toInt();
    this->setFont(QFont(fontStr, fontSize));
    
    auto toolbar = parent->getMainToolbar();
    toolbar->setFontSize(fontSize);
}

void Editor::updateTabWidth() {
    int width = (QFontMetrics(editor->currentCharFormat().font()).averageCharWidth())*4;
    editor->setTabStopDistance(width);
}

bool Editor::isUntitled() {
    if (filePath=="untitled") {
        return true;
    }
    return false;
}

void Editor::setUntitled(bool untitled) {
    if (untitled) {
        filePath = "untitled";
    }
}

QString Editor::path() {
    return filePath;
}

void Editor::setPath(QString path) {
    filePath = path;
}

bool Editor::isModified() {
    return modified;
}

void Editor::setModified(bool mod) {
    modified = mod;
    Window::setStatusBarModified(mod);

    if (mod == false) {
        setSavedContent(editor->toPlainText());
    }
}

void Editor::setEditorText(QString text) {
    QString name = repository->getSyntaxForFile(filePath);
    highlight->setCurrentLanguage(repository->getLanguage(name));
    langName = name;
    
    auto toolbar = parent->getMainToolbar();
    toolbar->setSyntaxName(name);

    editor->setPlainText(text);
}

void Editor::syntaxHighlight(QString id) {
    highlight->setCurrentLanguage(repository->getLanguage(id));
    langName = id;
}

QString Editor::currentID() {
    QString name = langName;
    if (name == "") {
        name = "Plain Text";
    }
    return name;
}

void Editor::setHasFoundText(bool found) {
    foundText = found;
}

bool Editor::hasFoundText() {
    return foundText;
}

void Editor::setSavedContent(QString content) {
    lastSavedContent = content;
}

QString Editor::saveContent() {
    return lastSavedContent;
}

void Editor::displayFinder() {
    if (finder->isVisible()) {
        finder->clear();
        finder->hide();
    } else {
        finder->show();
    }
}

void Editor::contextMenuEvent(QContextMenuEvent *) {
    EditorContextMenu *menu = new EditorContextMenu;
    menu->exec(QCursor::pos());
    menu->show();
}

void Editor::onModified() {
    if (editor->document()->isModified()) {
        if (!foundText) {
            modified = true;
            Window::setStatusBarModified(true);
        }
    }
}

void Editor::highlightCurrentLine() {
    QTextEdit::ExtraSelection select;
    select.format.setBackground(QColor(colorID));
    select.format.setProperty(QTextFormat::FullWidthSelection, true);
    select.cursor = editor->textCursor();

    QList<QTextEdit::ExtraSelection> list;
    list.append(select);
    editor->setExtraSelections(list);

    Window::setStatusBarLineCount(editor->textCursor().blockNumber()+1);
}

//TextEdit class
TextEdit::TextEdit(Editor *p) {
    parent = p;
}

bool TextEdit::canInsertFromMimeData(const QMimeData *source) {
    if (source->hasHtml() || source->hasText()) {
        return true;
    }
    
    return false;
}

void TextEdit::insertFromMimeData(const QMimeData *source) {
    this->insertPlainText(source->text());
}

// This function handles all key-press events in the editor
// Auto-indent happens here
void TextEdit::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Tab) {
        auto cursor = this->textCursor();
        auto selected = cursor.selectedText();
        
        if (selected.contains("\u2029")) {
            QString tab = "    ";
            if (Window::useTabs->isChecked())
                tab = "\t";
                
            QString newSelection = "";
            newSelection = tab;
            
            for (QChar c : selected) {
                newSelection += c;
            
                if (c == "\u2029")
                    newSelection += tab;
            }
            
            parent->editor->insertPlainText(newSelection);
        } else {
		    if (!Window::useTabs->isChecked())
			    parent->editor->insertPlainText("    ");
            else
			    parent->editor->insertPlainText("\t");
        }
		
		return;
		
    // TODO: For these sections, we may want some kind of lookup, rather than this big if-else
    } else if (Window::intelIndent->isChecked() && parent->autoindent) {
        if (event->key() == Qt::Key_BraceLeft) {
	        QString currentLang = parent->currentID();
	        if (currentLang == "C" || currentLang == "C#" || currentLang == "C++"
	            || currentLang == "CSS" || currentLang == "D" || currentLang == "Go"
	            || currentLang == "Java" || currentLang == "JavaScript" || currentLang == "JSON"
	            || currentLang == "Objective-C" || currentLang == "Objective-C++" || currentLang == "Pony"
	            || currentLang == "Rust" || currentLang == "Vala") {
	            indent_next = true;    
	        }
	    } else if (event->key() == Qt::Key_BraceRight) {
	        QString currentLang = parent->currentID();
	        if (currentLang == "C" || currentLang == "C#" || currentLang == "C++"
	            || currentLang == "CSS" || currentLang == "D" || currentLang == "Go"
	            || currentLang == "Java" || currentLang == "JavaScript" || currentLang == "JSON"
	            || currentLang == "Objective-C" || currentLang == "Objective-C++" || currentLang == "Pony"
	            || currentLang == "Rust" || currentLang == "Vala") {
	            unindent_next = true;    
	        }
	    } else if (event->key() == Qt::Key_Colon) {
	        QString currentLang = parent->currentID();
	        if (currentLang == "Python") {
	            indent_next = true;
	        }
	    } else if (event->key() == Qt::Key_BracketLeft) {
	        QString currentLang = parent->currentID();
	        if (currentLang == "JSON") {
	            indent_next = true;
	        }
	    } else if (event->key() == Qt::Key_BracketRight) {
	        QString currentLang = parent->currentID();
	        if (currentLang == "JSON") {
	            unindent_next = true;
	        }
	    }
    } else if (!Window::intelIndent->isChecked() || !parent->autoindent) {
        indent_next = false;
        unindent_next = false;
    }

    // If the user wants autoindent, then do the work
    if (parent->autoindent) {
        if ((event->key()==Qt::Key_Enter)||(event->key()==Qt::Key_Return)) {
            int tabCount = 0;
            int spaceCount = 0;
            
            // First, we get the last line and count the number of tabs and spaces preceding
            QString lastLine = parent->editor->document()->findBlockByLineNumber(
                        parent->editor->textCursor().blockNumber()).text();
            
            for (int i = 0; i<lastLine.length(); i++) {
                QChar c = lastLine.at(i);
                
                if (c == '\t' ) {
                    if (Window::useTabs->isChecked()) {
                       ++tabCount;
                    } else {
                       spaceCount += 4;
                    }
                } else if (c == ' ') {
                    ++spaceCount;
                } else {
                    break;
                }
            }
            
            // If we need to automatically indent the next line, increase the tab/space count
            // TODO: The increased amount should be based on the detection from the loop above
            if (indent_next) {
                if (Window::useTabs->isChecked()) {
                    ++tabCount;
                } else {
                    spaceCount += 4;
                }
                
                indent_next = false;
                
            // Otherwise, we need to decrease the amount to indent, and if necessary, unindent the last line
            // For example, we don't want to leave a closing curly-brace indented if it forms the end of a block
            } else if (unindent_next) {
                if (Window::useTabs->isChecked()) {
                    --tabCount;
                } else {
                    spaceCount -= 4;
                }
                
                // Re-construct the last line
                QString lastLine_mod = "";
                if (Window::useTabs->isChecked()) {
                    for (int i = 0; i<tabCount; i++) lastLine_mod += "\t";											
					for (int i = 0; i<spaceCount; i++) lastLine_mod += " ";
                } else {
                	int count = spaceCount + (tabCount * 4);
                    for (int i = 0; i<count; i++) lastLine_mod += " ";
                }
                
                lastLine_mod += lastLine.trimmed();
                
                // And find and replace the last occurrence of it
                QTextDocument *doc = parent->editor->document();
                QTextCursor cursor(doc);
                cursor = doc->find(lastLine,cursor,QTextDocument::FindWholeWords | QTextDocument::FindCaseSensitively);
                while (!cursor.isNull() && !cursor.atEnd()) {
                    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
                    cursor = doc->find(lastLine,cursor,QTextDocument::FindWholeWords | QTextDocument::FindCaseSensitively);
                }
                cursor.insertText(lastLine_mod);
                
                unindent_next = false;
            }
                
            // Finally, indent the current line
            if (tabCount>0 || spaceCount>0) {
                QTextEdit::keyPressEvent(event);
                
                if (Window::useTabs->isChecked()) {
                    for (int i = 0; i<tabCount; i++) {
                        parent->editor->insertPlainText("\t");
                    }
																				
					for (int i = 0; i<spaceCount; i++) {
						parent->editor->insertPlainText(" ");
					}
                } else {
                	int count = spaceCount + (tabCount * 4);
                    for (int i = 0; i<count; i++) {
                        parent->editor->insertPlainText(" ");
                    }
                }
            } else {
                QTextEdit::keyPressEvent(event);
            }
        } else {
            QTextEdit::keyPressEvent(event);
        }
    } else {
        QTextEdit::keyPressEvent(event);
    }
}

