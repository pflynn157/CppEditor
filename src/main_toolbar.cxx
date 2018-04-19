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
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE..
#include <QIcon>
#include <QPixmap>
#include <QFont>
#include <QUrl>
#include <QCursor>
#include <QVariant>
#include <QStringList>
#include <KF5/KSyntaxHighlighting/Definition>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "main_toolbar.hh"
#include "global/slots.hh"
#include "tabpane.hh"
#include "lang/lang-parser.hh"
#include "global.hh"
#include "icon.hh"

QComboBox *MainToolBar::syntaxmenu;
FontSpinner *MainToolBar::fontSize;

using namespace CppLib;
using namespace KSyntaxHighlighting;

MainToolBar::MainToolBar(QMainWindow *parentWindow) {
    parent = parentWindow;
    this->setContextMenuPolicy(Qt::PreventContextMenu);

    newFile = new ToolButton("newFile");
    openFile = new ToolButton("openFile");
    saveFile = new ToolButton("saveFile");
    saveFileAs = new ToolButton("saveFileAs");
    cut = new ToolButton("cut");
    copy = new ToolButton("copy");
    paste = new ToolButton("paste");
    undo = new ToolButton("undo");
    redo = new ToolButton("redo");
    syntaxmenu = new QComboBox;
    fontSize = new FontSpinner;

    syntaxmenu->setVisible(QVariant(Settings::getSetting("toolbar/syntaxmenu","true")).toBool());
    auto list = repository->definitions();
    QStringList syntaxItems;
    for (int i = 0; i<list.size(); i++) {
        syntaxItems.push_back(list.at(i).name());
    }
    syntaxItems.sort(Qt::CaseInsensitive);
    syntaxItems.push_front("Plain Text");
    syntaxmenu->addItems(syntaxItems);

    newFile->setIcon(IconManager::getIcon("document-new"));
    openFile->setIcon(IconManager::getIcon("document-open"));
    saveFile->setIcon(IconManager::getIcon("document-save"));
    saveFileAs->setIcon(IconManager::getIcon("document-save-as"));
    cut->setIcon(IconManager::getIcon("edit-cut"));
    copy->setIcon(IconManager::getIcon("edit-copy"));
    paste->setIcon(IconManager::getIcon("edit-copy"));
    undo->setIcon(IconManager::getIcon("edit-undo"));
    redo->setIcon(IconManager::getIcon("edit-redo"));

    newFile->setToolTip(trans("New file"));
    openFile->setToolTip(trans("Open a file"));
    saveFile->setToolTip(trans("Save current file"));
    saveFileAs->setToolTip(trans("Save current file as"));
    fontSize->setToolTip(trans("Change font size"));

    connect(newFile,&ToolButton::clicked,new Slots,&Slots::newFileSlot);
    connect(openFile,&ToolButton::clicked,new Slots,&Slots::openFileSlot);
    connect(saveFile,&ToolButton::clicked,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&ToolButton::clicked,new Slots,&Slots::saveFileAsSlot);
    connect(cut,&ToolButton::clicked,new Slots,&Slots::cutSlot);
    connect(copy,&ToolButton::clicked,new Slots,&Slots::copySlot);
    connect(paste,&ToolButton::clicked,new Slots,&Slots::pasteSlot);
    connect(undo,&ToolButton::clicked,new Slots,&Slots::undoSlot);
    connect(redo,&ToolButton::clicked,new Slots,&Slots::redoSlot);
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

void MainToolBar::onFontSizeChanged() {
    QFont font = TabPane::currentWidget()->font();
    font.setPointSize(fontSize->value());
    TabPane::currentWidget()->setFont(font);
}

void MainToolBar::onComboTextChanged(QString item) {
    TabPane::currentWidget()->syntaxHighlight(item);
}

//ToolButton
//This class contains a slightly modified QToolButton for our toolbar
//The main difference lies in the ability to hide the button

ToolButton::ToolButton(QString id) {
    buttonId = id;
    this->setVisible(QVariant(Settings::getSetting("toolbar/"+id,"true")).toBool());
}

void ToolButton::mousePressEvent(QMouseEvent *event) {
    if (event->button()==Qt::RightButton) {
        QMenu *popup = new QMenu;
        QAction *hide = new QAction("Hide button",popup);
        connect(hide,&QAction::triggered,this,&ToolButton::hideButton);
        popup->addAction(hide);
        popup->exec(QCursor::pos());
    } else {
        QToolButton::mousePressEvent(event);
    }
}

void ToolButton::hideButton() {
    Settings::writeSetting("toolbar/"+buttonId,"false");
    TabPane::buttonHidden->setText("You must restart for changes to take effect.\n"
                                   "To show the button again, change the value of <"+buttonId+">"
                                   " under <toolbar> to \"true\" and restart.");
    TabPane::buttonHidden->animatedShow();
}

//FontSpinner
//This is a slightly modified QSpinner for setting the font size
//The font size is only changed on the current tab

FontSpinner::FontSpinner() {
    this->setVisible(QVariant(Settings::getSetting("toolbar/fontsize","true")).toBool());
    this->setMinimum(1);
    this->setMaximum(100);
    this->setValue(TabPane::currentWidget()->fontInfo().pointSize());
}
