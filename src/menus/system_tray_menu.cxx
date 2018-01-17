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
#include "system_tray_menu.hh"
#include "../global/slots.hh"

SystemTrayMenu::SystemTrayMenu(QMainWindow *parentWin) {
    parent = parentWin;

    showHideWindow = new QAction("Hide Window",this);
    saveCurrentFile = new QAction("Save current file",this);
    quit = new QAction("Exit",this);

    showHideWindow->setCheckable(true);

    connect(showHideWindow,&QAction::triggered,this,&SystemTrayMenu::onShowHideWindow);
    connect(saveCurrentFile,&QAction::triggered,new Slots,&Slots::saveFileSlot);
    connect(quit,&QAction::triggered,this,&SystemTrayMenu::onQuitClicked);

    this->addAction(showHideWindow);
    this->addAction(saveCurrentFile);
    this->addAction(quit);
}

SystemTrayMenu::~SystemTrayMenu() {
    delete showHideWindow;
    delete saveCurrentFile;
    delete quit;
}

void SystemTrayMenu::onShowHideWindow() {
    if (showHideWindow->isChecked()) {
        parent->hide();
    } else {
        parent->showNormal();
    }
}

void SystemTrayMenu::onQuitClicked() {
	Slots *s = new Slots;
	s->quitSlot(parent);	
}
