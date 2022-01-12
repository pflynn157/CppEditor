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
#include <QApplication>
#include <QFile>
#include <QFileInfo>

#include <cstdlib>
#include <string>
#include <iostream>

#ifndef WIN32
#include <unistd.h>
#endif

#include "global.hpp"
#include "window.hpp"
#include "tabpane.hpp"
#include "editor.hpp"
#include "global/file_actions.hpp"
#include "global/recent.hpp"
#include "icon.hpp"

QSourceRepository *repository;
QSettings settings("CppEditor", "CppEditor");

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    QCoreApplication::setApplicationName("CppEditor");
    QCoreApplication::setOrganizationName("CppEditor");

    repository = new QSourceRepository;
    Recent::initRecentItems();
    Editor::updateSettings();
    IconManager::init();

    Window *window = new Window;
    window->show();

    for (int i = 1; i<argc; i++) {
        QString fullPath = QFileInfo(argv[i]).absoluteFilePath();
        Window::addFile(fullPath);
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

