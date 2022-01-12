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
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QKeyEvent>
#include <QMenu>
#include <QContextMenuEvent>
#include <QTextCharFormat>
#include <QMimeData>
#include <qsourcerepository.h>
#include <qsourcehighliter.h>

#include "finder.hpp"
#include "window.hpp"

class Finder;
class TextEdit;

class Editor : public QFrame {
    Q_OBJECT
    friend class TextEdit;
public:
    static bool autoindent;
    static QString colorID;
    static void updateSettings();
    explicit Editor(QString path, Window *parent);
    TextEdit *editorWidget();
    void updateFont();
    void updateTabWidth();
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
    void displayFinder();
protected:
    void contextMenuEvent(QContextMenuEvent *);
private:
    Window *parent;
    QVBoxLayout *layout;
    TextEdit *editor;
    Finder *finder;
    QString filePath;
    QSourceHighliter *highlight;
    QString langName = "";
    bool modified = false;
    bool foundText = false;
    QString lastSavedContent = "";
private slots:
    void onModified();
    void highlightCurrentLine();
};

class TextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit TextEdit(Editor *p);
protected:
    bool canInsertFromMimeData(const QMimeData *source);
    void insertFromMimeData(const QMimeData *source);
    void keyPressEvent(QKeyEvent *event);
private:
    Editor *parent;
    bool indent_next = false;
    bool unindent_next = false;
};
