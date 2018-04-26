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
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QKeyEvent>
#include <QMenu>
#include <QContextMenuEvent>
#include <QTextCharFormat>
#include <QMimeData>
#include <KF5/KSyntaxHighlighting/SyntaxHighlighter>
#include <KF5/SonnetUi/Sonnet/SpellCheckDecorator>

#include "format_toolbar.hh"
#include "finder.hh"

using namespace KSyntaxHighlighting;

class Finder;
class TextEdit;

class Editor : public QFrame {
    Q_OBJECT
    friend class TextEdit;
public:
    static bool autoindent;
    static QString colorID;
    static void updateSettings();
    explicit Editor(QString path);
    TextEdit *editorWidget();
    bool isUntitled();
    void setUntitled(bool untitled);
    QString path();
    void setPath(QString path);
    bool isModified();
    void setModified(bool mod);
    void setEditorText(QString text);
    void syntaxHighlight(QString id);
    QString currentID();
    void setHasFoundText(bool found);
    bool hasFoundText();
    void setSavedContent(QString content);
    QString saveContent();
    void displayFormatToolbar(bool dsp);
    void displayFinder();
    bool isRtf();
    void shouldSpellCheck(bool check);
protected:
    void contextMenuEvent(QContextMenuEvent *);
    void insertFromMimeData(const QMimeData *source);
private:
    QVBoxLayout *layout;
    FormatToolbar *formatToolbar;
    TextEdit *editor;
    Finder *finder;
    QString filePath;
    SyntaxHighlighter *highlight;
    bool modified = false;
    bool foundText = false;
    QString lastSavedContent = "";
    Sonnet::SpellCheckDecorator *spellcheck;
private slots:
    void onModified();
    void highlightCurrentLine();
};

class TextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit TextEdit(Editor *p);
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Editor *parent;
};
