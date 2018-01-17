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
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "lang-manager.hh"
#include "../tinyxml2.h"
#include "../global/file_actions.hh"

QString LangManager::langName = "default";
QString LangManager::langPath = "default";

using namespace CppLib;
using namespace tinyxml2;

QStringList *LangManager::allLangs() {
    QStringList *langs = new QStringList;
    QFile file(":/lang/rsc/available.txt");
    if (file.open(QFile::ReadOnly)) {
        QTextStream reader(&file);
        while (!reader.atEnd()) {
            langs->push_back(reader.readLine());
        }
    }
    return langs;
}

QString LangManager::getFile(QString name) {
    QString path = ":/lang/rsc/";
    QDir dir(path);
    QStringList items = dir.entryList(QDir::Files);
    for (int i = 0; i<items.size(); i++) {
        if (QString(items.at(i)).endsWith(".xml")) {
            XMLDocument *doc = new XMLDocument;
            QString content = FileActions::fileContents(QString(path+items.at(i)));
            doc->Parse(content.toStdString().c_str());
            XMLElement *root = doc->FirstChildElement("language");
            if (root==nullptr) {
                return nullptr;
            }
            QString langName = QString(root->Attribute("name"));
            if (langName==name) {
                path+=items.at(i);
                break;
            }
        } else {
            continue;
        }
    }
    return path;
}

void LangManager::init() {
    langName = Settings::getSetting("language/name","default");
    langPath = Settings::getSetting("language/path","default");
    std::cout << "Application Language: " << langName.toStdString() << std::endl;
    std::cout << "Language File Path: " << langPath.toStdString() << std::endl;
}
