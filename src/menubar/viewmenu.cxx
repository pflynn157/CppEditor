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
#include "viewmenu.hh"
#include "../window.hh"
#include "../lang/lang-parser.hh"
#include "../icon.hh"

ViewMenu::ViewMenu(QMainWindow *parent) {
    parentWindow = parent;
    this->setTitle(trans("View"));

    fullscreen = new QAction(trans("Fullscreen"),this);
    projectPane = new QAction(trans("Display Project Panel"),this);
    richTextPane = new QAction(trans("Display Rich Text Previewer"),this);

    richTextPane->setCheckable(true);
    richTextPane->setChecked(false);

    projectPane->setCheckable(true);
    projectPane->setChecked(false);

    fullscreen->setIcon(IconManager::getIcon("view-fullscreen"));

    connect(fullscreen,&QAction::triggered,this,&ViewMenu::onFullscreenClicked);
    connect(projectPane,&QAction::triggered,this,&ViewMenu::onProjectPaneClicked);
    connect(richTextPane,&QAction::triggered,this,&ViewMenu::onRichTextPaneClicked);

    this->addAction(fullscreen);
    this->addAction(projectPane);
    this->addAction(richTextPane);
}

ViewMenu::~ViewMenu() {
    delete fullscreen;
    delete projectPane;
}

void ViewMenu::onFullscreenClicked() {
    if (parentWindow->isFullScreen()) {
        if (wasMax) {
            parentWindow->showMaximized();
        } else {
            parentWindow->showNormal();
        }
    } else {
        if (parentWindow->isMaximized()) {
            wasMax = true;
        } else {
            wasMax = false;
        }
        parentWindow->showFullScreen();
    }
}

void ViewMenu::onProjectPaneClicked() {
    Window::displayProjectPane();
}

void ViewMenu::onRichTextPaneClicked() {
    Window::displayRichTextPane();
}
