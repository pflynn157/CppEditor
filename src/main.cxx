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
#include <QApplication>
#include <QFile>
#include <cstdlib>
#include <string>
#include <iostream>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#include <unistd.h>
#endif

#include "global.hh"
#include "window.hh"
#include "tabpane.hh"
#include "editor.hh"
#include "global/file_actions.hh"
#include "global/recent.hh"
#include "template/template.hh"
#include "macros.hh"
#include "lang/lang-manager.hh"
#include "icon.hh"
#include "ipc.hh"

Repository *repository;

using namespace CppLib;

int main(int argc, char *argv[]) {
    Settings::registerApp("CppEditor");
    Settings::setDefaultSettingsFile(":/rsc/settings_default.xml");
    Settings::initPaths();

    QApplication app(argc,argv);
    QCoreApplication::setApplicationName("CppEditor");
    QCoreApplication::setOrganizationName("CppEditor");

    IPC *ipc = new IPC;
    if (ipc->isRegistered()) {
        std::cout << "[DBUS] CppEditor has been registered." << std::endl;
    }

    repository = new Repository;
    Recent::initRecentItems();
    Template::initTemplates();
    Editor::updateSettings();
    LangManager::init();
    IconManager::init();

    Window window;
    window.show();

    for (int i = 1; i<argc; i++) {
        Window::addFile(argv[i]);
    }
#ifndef HAIKU_OS
#ifndef _WIN32
    if (getuid()==0) {
        TabPane::rootStatus->show();
    }
#endif
#endif
    return app.exec();
}
