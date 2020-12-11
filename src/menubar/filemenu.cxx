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
#include <QKeySequence>
#include <QProcess>

#include "filemenu.hpp"
#include "../global/slots.hpp"
#include "../icon.hpp"

RecentMenu *FileMenu::recentMenu;

FileMenu::FileMenu(QMainWindow *window) {
    this->setTitle("File");
    win = window;

    newWin = new QAction("New Window", this);
    newFile = new QAction("New",this);
    openFile = new QAction("Open",this);
    recentMenu = new RecentMenu;
    saveFile = new QAction("Save",this);
    saveFileAs = new QAction("Save As",this);
    quit = new QAction("Quit",this);

    newFile->setIcon(IconManager::getIcon("document-new"));
    openFile->setIcon(IconManager::getIcon("document-open"));
    saveFile->setIcon(IconManager::getIcon("document-save"));
    saveFileAs->setIcon(IconManager::getIcon("document-save-as"));
    quit->setIcon(IconManager::getIcon("application-exit"));

    newFile->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_N));
    openFile->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_O));
    saveFile->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_S));
    saveFileAs->setShortcut(QKeySequence(Qt::SHIFT+Qt::CTRL+Qt::Key_S));
    quit->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));

    connect(newWin, &QAction::triggered, this, &FileMenu::onNewWindowClicked);
    connect(newFile,&QAction::triggered,new Slots,&Slots::newFileSlot);
    connect(openFile,&QAction::triggered,new Slots,&Slots::openFileSlot);
    connect(saveFile,&QAction::triggered,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&QAction::triggered,new Slots,&Slots::saveFileAsSlot);
    connect(quit,&QAction::triggered,this,&FileMenu::onQuitClicked);

    this->addAction(newWin);
    this->addAction(newFile);
    this->addAction(openFile);
    this->addMenu(recentMenu);
    this->addAction(saveFile);
    this->addAction(saveFileAs);
    this->addAction(quit);
}

FileMenu::~FileMenu() {
    delete newWin;
    delete newFile;
    delete openFile;
    delete saveFile;
    delete saveFileAs;
    delete quit;
    delete recentMenu;
}

void FileMenu::onNewWindowClicked() {
    QProcess::startDetached("CppEditor", QStringList() << "--single");
}

void FileMenu::onQuitClicked() {
	Slots *s = new Slots;
	s->quitSlot(win);	
}
