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
#include <QApplication>
#include <QMessageBox>
#include <iostream>

#include "helpmenu.hh"
#include "../lang/lang-dialog.hh"
#include "../global/file_actions.hh"
#include "../lang/lang-parser.hh"

HelpMenu::HelpMenu() {
    this->setTitle(trans("Help"));

    switchLang = new QAction(trans("Switch Language"),this);
    aboutQt = new QAction(trans("About Qt"),this);
    about = new QAction(trans("About"),this);

	QPixmap aboutIcon(":/icons/help-about.png");

#ifdef NO_THEME_ICONS
	about->setIcon(aboutIcon);
#else
	about->setIcon(QIcon::fromTheme("help-about",aboutIcon));
#endif

    connect(switchLang,&QAction::triggered,this,&HelpMenu::onSwitchLangClicked);
    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(about,&QAction::triggered,this,&HelpMenu::onAboutClicked);

    this->addAction(switchLang);
    this->addAction(aboutQt);
    this->addAction(about);
}

HelpMenu::~HelpMenu() {
    delete switchLang;
    delete aboutQt;
    delete about;
}

void HelpMenu::onSwitchLangClicked() {
    LangDialog dialog;
    dialog.exec();
}

void HelpMenu::onAboutClicked() {
    QMessageBox msg;
    msg.setWindowTitle(trans("About CppEditor"));
    msg.setText("CppEditor\n"
                "An advanced, cross-platform text editor written in C++ using the Qt libraries.\n\n"
                "Written by pdf4664 <pdf4664@outlook.com>\n");
    msg.setDetailedText("License:\n"+FileActions::fileContents(":/rsc/license.txt"));
#ifdef _WIN32
    QString extra = msg.text();
    extra+="\nBuilt for Windows OS";
    msg.setText(extra);
#endif
    msg.exec();
}
