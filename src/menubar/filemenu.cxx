// Copyright 2017 Patrick Flynn
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
#include <QIcon>
#include <QPixmap>

#include "filemenu.hh"
#include "../global/slots.hh"
#include "../lang/lang-parser.hh"

RecentMenu *FileMenu::recentMenu;

FileMenu::FileMenu(QMainWindow *window) {
    this->setTitle(trans("File"));
    win = window;

    newFile = new QAction(trans("New"),this);
    openFile = new QAction(trans("Open"),this);
    recentMenu = new RecentMenu;
    saveFile = new QAction(trans("Save"),this);
    saveFileAs = new QAction(trans("Save As"),this);
    quit = new QAction(trans("Quit"),this);

    QPixmap newDocIcon(":/icons/document-new.png");
    QPixmap openIcon(":/icons/document-open.png");
    QPixmap saveIcon(":/icons/document-save.png");
    QPixmap saveAsIcon(":/icons/document-save-as.png");
    QPixmap quitIcon(":/icons/application-exit.png");

#ifdef NO_THEME_ICONS
    newFile->setIcon(newDocIcon);
    openFile->setIcon(openIcon);
    saveFile->setIcon(saveIcon);
    saveFileAs->setIcon(saveAsIcon);
    quit->setIcon(quitIcon);
#else
    newFile->setIcon(QIcon::fromTheme("document-new",newDocIcon));
    openFile->setIcon(QIcon::fromTheme("document-open",openIcon));
    saveFile->setIcon(QIcon::fromTheme("document-save",saveIcon));
    saveFileAs->setIcon(QIcon::fromTheme("document-save-as",saveAsIcon));
    quit->setIcon(QIcon::fromTheme("application-exit",quitIcon));
#endif

    connect(newFile,&QAction::triggered,new Slots,&Slots::newFileSlot);
    connect(openFile,&QAction::triggered,new Slots,&Slots::openFileSlot);
    connect(saveFile,&QAction::triggered,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&QAction::triggered,new Slots,&Slots::saveFileAsSlot);
    connect(quit,&QAction::triggered,this,&FileMenu::onQuitClicked);

    this->addAction(newFile);
    this->addAction(openFile);
    this->addMenu(recentMenu);
    this->addAction(saveFile);
    this->addAction(saveFileAs);
    this->addAction(quit);
}

FileMenu::~FileMenu() {
    delete newFile;
    delete openFile;
    delete saveFile;
    delete saveFileAs;
    delete quit;
    delete recentMenu;
}

void FileMenu::onQuitClicked() {
	Slots *s = new Slots;
	s->quitSlot(win);	
}
