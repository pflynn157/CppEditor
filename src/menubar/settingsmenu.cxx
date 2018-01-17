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
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE..
#include <QIcon>
#include <QPixmap>
#include <QFontDialog>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QVariant>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "settingsmenu.hh"
#include "../tabpane.hh"
#include "../global/file_actions.hh"
#include "../tabpane.hh"
#include "../editor.hh"
#include "../window.hh"
#include "../settings/settings_dialog.hh"
#include "../lang/lang-parser.hh"

using namespace CppLib;

SettingsMenu::SettingsMenu() {
    this->setTitle(trans("Settings"));

    openSettingsDialog = new QAction(trans("Open Settings Dialog"),this);
    setTheme = new QAction(trans("Set program theme"),this);
    sysTheme = new QAction(trans("Use system theme"),this);
    openSettingsFile = new QAction(trans("Open settings file"),this);

    connect(openSettingsDialog,&QAction::triggered,this,&SettingsMenu::onOpenSettingsDialogClicked);
    connect(setTheme,&QAction::triggered,this,&SettingsMenu::onSetThemeClicked);
    connect(sysTheme,&QAction::triggered,this,&SettingsMenu::onSysThemeClicked);
    connect(openSettingsFile,&QAction::triggered,this,&SettingsMenu::onOpenSettingsFileClicked);

    this->addAction(openSettingsDialog);

    themeMenu = new QMenu(trans("Themes"));
    this->addMenu(themeMenu);

    themeMenu->addAction(setTheme);
    themeMenu->addAction(sysTheme);

    if (Settings::settingsPath!=nullptr) {
        this->addAction(openSettingsFile);
    }
}

SettingsMenu::~SettingsMenu() {
    delete openSettingsDialog;
    delete themeMenu;
    delete setTheme;
    delete sysTheme;
    delete openSettingsFile;
}

void SettingsMenu::onOpenSettingsDialogClicked() {
    SettingsDialog dialog;
    dialog.exec();
}

void SettingsMenu::onSetThemeClicked() {
    QFileDialog cssChooser;
    cssChooser.setWindowTitle(trans("Choose CSS Theme"));
    cssChooser.setAcceptMode(QFileDialog::AcceptOpen);
    cssChooser.exec();
    if (cssChooser.selectedFiles().size()==0) {
        return;
    }
    QString file = cssChooser.selectedFiles().at(0);
    Settings::writeSetting("window","css",file,"");
    TabPane::settingsSaved->animatedShow();
}

void SettingsMenu::onSysThemeClicked() {
    Settings::writeSetting("window","css","default","");
    TabPane::settingsSaved->animatedShow();
}

void SettingsMenu::onOpenSettingsFileClicked() {
    FileActions::processOpenFile(Settings::settingsPath);
}
