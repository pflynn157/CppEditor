// Copyright 2017-2018, 2020-201 Patrick Flynn
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
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE..
#include <QIcon>
#include <QPixmap>
#include <QFont>
#include <QStringList>

#include "main_toolbar.hpp"
#include "global/slots.hpp"
#include "tabpane.hpp"
#include "global.hpp"
#include "icon.hpp"

MainToolBar::MainToolBar(QMainWindow *parentWindow)
    : newFile(new QToolButton),
      openFile(new QToolButton),
      saveFile(new QToolButton),
      saveFileAs(new QToolButton),
      cut(new QToolButton),
      copy(new QToolButton),
      paste(new QToolButton),
      undo(new QToolButton),
      redo(new QToolButton)
{
    parent = parentWindow;
    this->setContextMenuPolicy(Qt::PreventContextMenu);
    this->setMovable(false);

    syntaxmenu = new QComboBox;
    fontSize = new QSpinBox;
    
    QStringList syntaxItems = repository->getSyntaxList();
    syntaxItems.sort(Qt::CaseInsensitive);
    syntaxItems.push_front("Plain Text");
    syntaxmenu->addItems(syntaxItems);
    
    int size = settings.value("editor/font_size", 12).toInt();

    fontSize->setMinimum(1);
    fontSize->setMaximum(100);
    fontSize->setValue(size);

    newFile->setIcon(IconManager::getIcon("document-new"));
    openFile->setIcon(IconManager::getIcon("document-open"));
    saveFile->setIcon(IconManager::getIcon("document-save"));
    saveFileAs->setIcon(IconManager::getIcon("document-save-as"));
    cut->setIcon(IconManager::getIcon("edit-cut"));
    copy->setIcon(IconManager::getIcon("edit-copy"));
    paste->setIcon(IconManager::getIcon("edit-copy"));
    undo->setIcon(IconManager::getIcon("edit-undo"));
    redo->setIcon(IconManager::getIcon("edit-redo"));

    newFile->setToolTip("New file");
    openFile->setToolTip("Open a file");
    saveFile->setToolTip("Save current file");
    saveFileAs->setToolTip("Save current file as");
    cut->setToolTip("Cut text");
    copy->setToolTip("Copy text");
    paste->setToolTip("Paste text");
    undo->setToolTip("Undo last edit");
    redo->setToolTip("Redo last edit");
    fontSize->setToolTip("Change font size");

    connect(newFile,&QToolButton::clicked,new Slots,&Slots::newFileSlot);
    connect(openFile,&QToolButton::clicked,new Slots,&Slots::openFileSlot);
    connect(saveFile,&QToolButton::clicked,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&QToolButton::clicked,new Slots,&Slots::saveFileAsSlot);
    connect(cut,&QToolButton::clicked,new Slots,&Slots::cutSlot);
    connect(copy,&QToolButton::clicked,new Slots,&Slots::copySlot);
    connect(paste,&QToolButton::clicked,new Slots,&Slots::pasteSlot);
    connect(undo,&QToolButton::clicked,new Slots,&Slots::undoSlot);
    connect(redo,&QToolButton::clicked,new Slots,&Slots::redoSlot);
    connect(syntaxmenu,SIGNAL(currentTextChanged(QString)),this,SLOT(onComboTextChanged(QString)));
    connect(fontSize,SIGNAL(valueChanged(int)),this,SLOT(onFontSizeChanged()));

    this->addWidget(newFile);
    this->addWidget(openFile);
    this->addWidget(saveFile);
    this->addWidget(saveFileAs);
    this->addSeparator();
    this->addWidget(cut);
    this->addWidget(copy);
    this->addWidget(paste);
    this->addWidget(undo);
    this->addWidget(redo);
    this->addSeparator();
    this->addWidget(syntaxmenu);
    this->addWidget(fontSize);
}

MainToolBar::~MainToolBar() {
    delete newFile;
    delete openFile;
    delete saveFile;
    delete saveFileAs;
    delete cut;
    delete copy;
    delete paste;
    delete syntaxmenu;
    delete fontSize;
}

void MainToolBar::setFontSize(int val) {
    fontSize->setValue(val);
}

void MainToolBar::setSyntaxName(QString name) {
    syntaxmenu->setCurrentText(name);
}

void MainToolBar::onFontSizeChanged() {
    QFont font = TabPane::currentWidget()->font();
    font.setPointSize(fontSize->value());
    TabPane::currentWidget()->setFont(font);
}

void MainToolBar::onComboTextChanged(QString item) {
    TabPane::currentWidget()->syntaxHighlight(item);
}

