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
#include <QInputDialog>

#include "viewmenu.hpp"
#include "../window.hpp"
#include "../icon.hpp"

ViewMenu::ViewMenu(Window *parent) {
    parentWindow = parent;
    this->setTitle("View");

    fullscreen = new QAction("Fullscreen",this);
    setWinTitle = new QAction("Set Window Title", this);
    projectPane = new QAction("Display Project Panel",this);

    projectPane->setCheckable(true);
    projectPane->setChecked(false);

    fullscreen->setIcon(IconManager::getIcon("view-fullscreen"));

    connect(fullscreen, &QAction::triggered, this, &ViewMenu::onFullscreenClicked);
    connect(setWinTitle, &QAction::triggered, this, &ViewMenu::onSetWinTitleClicked);
    connect(projectPane, &QAction::triggered, this, &ViewMenu::onProjectPaneClicked);

    this->addAction(fullscreen);
    this->addAction(setWinTitle);
    this->addAction(projectPane);
}

ViewMenu::~ViewMenu() {
    delete fullscreen;
    delete setWinTitle;
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

void ViewMenu::onSetWinTitleClicked() {
    QString title = QInputDialog::getText(parentWindow, "Change Window Title", "Enter new title:");

    if (title != "") {
        parentWindow->setTitle(title, true);
    }
}

void ViewMenu::onProjectPaneClicked() {
    Window::displayProjectPane();
}

