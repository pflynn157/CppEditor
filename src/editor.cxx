// Copyright 2017-2018 Patrick Flynn
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
#include <iostream>
#include <KF5/KSyntaxHighlighting/Definition>
#include <KF5/KSyntaxHighlighting/Theme>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "editor.hh"
#include "global.hh"
#include "window.hh"
#include "main_toolbar.hh"
#include "menus/editor_context.hh"

using namespace CppLib;
using namespace KSyntaxHighlighting;

bool Editor::autoindent = true;
QString Editor::colorID = "#d9d9d9";

void Editor::updateSettings() {
    Editor::autoindent = QVariant(Settings::getSetting("editor/autoindent","true")).toBool();
    Editor::colorID = Settings::getSetting("editor/line_color","#d9d9d9");
}

Editor::Editor(QString path) {
    filePath = path;

    connect(this,&QTextEdit::textChanged,this,&Editor::onModified);
    connect(this,&QTextEdit::cursorPositionChanged,this,&Editor::highlightCurrentLine);

    QTextDocument *doc = new QTextDocument();
    this->setDocument(doc);

    highlight = new SyntaxHighlighter(doc);
    highlight->setTheme(repository->defaultTheme(KSyntaxHighlighting::Repository::LightTheme));

    int width = (QFontMetrics(this->currentCharFormat().font()).averageCharWidth())*2;
    this->setTabStopWidth(width);
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
}

void Editor::setEditorText(QString text) {
    Definition def = repository->definitionForFileName(filePath);
    QString name = def.name();
    this->syntaxHighlight(name);
    MainToolBar::syntaxmenu->setCurrentText(name);

    this->setPlainText(text);
}

void Editor::syntaxHighlight(QString id) {
    highlight->setDefinition(repository->definitionForName(id));
}

QString Editor::currentID() {
    QString name = highlight->definition().name();
    if (name=="") {
        name="Plain Text";
    }
    return name;
}

void Editor::setHasFoundText(bool found) {
    foundText = found;
}

bool Editor::hasFoundText() {
    return foundText;
}

void Editor::keyPressEvent(QKeyEvent *event) {
    if (autoindent) {
        if ((event->key()==Qt::Key_Enter)||(event->key()==Qt::Key_Return)) {
            QString lastLine = this->document()->findBlockByLineNumber(this->textCursor().blockNumber()).text();
            int tabCount = 0;
            for (int i = 0; i<lastLine.length(); i++) {
                if (lastLine.at(i)!='\t') {
                    break;
                }
                tabCount++;
            }
            if (tabCount>0) {
                QTextEdit::keyPressEvent(event);
                for (int i = 0; i<tabCount; i++) {
                    this->insertPlainText("\t");
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

void Editor::contextMenuEvent(QContextMenuEvent *) {
    EditorContextMenu *menu = new EditorContextMenu;
    menu->exec(QCursor::pos());
    menu->show();
}

void Editor::insertFromMimeData(const QMimeData *source) {
    this->insertPlainText(source->text());
}

void Editor::onModified() {
    if (this->document()->isModified()) {
        if (!foundText) {
            modified = true;
            Window::setStatusBarModified(true);
        }
        if (Window::isRichTextPaneVisible()) {
            Window::setRichTextPane(this->toPlainText());
        }
    }
}

void Editor::highlightCurrentLine() {
    QTextEdit::ExtraSelection select;
    select.format.setBackground(QColor(colorID));
    select.format.setProperty(QTextFormat::FullWidthSelection, true);
    select.cursor = this->textCursor();

    QList<QTextEdit::ExtraSelection> list;
    list.append(select);
    this->setExtraSelections(list);

    Window::setStatusBarLineCount(this->textCursor().blockNumber()+1);
}
