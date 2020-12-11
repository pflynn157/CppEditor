// Copyright 2017, 2020 Patrick Flynn
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
#include <QDir>
#include <QTextStream>

#include "recent.hpp"
#include "../menubar/filemenu.hpp"

QStringList *Recent::items;
QString Recent::filePath;

void Recent::initRecentItems() {
    items = new QStringList;

    QString path = QDir::homePath();
#ifdef _WIN32
    if (!path.endsWith("\\")) {
        path+="\\";
    }
#else
    if (!path.endsWith("/")) {
        path+="/";
    }
#endif
#ifdef HAIKU_OS
	path+="config/settings/CppEditor";
#elif _WIN32
    path+="\\AppData\\Local\\CppEditor";
#else
    path+=".CppEditor";
#endif
    if (!QDir(path).exists()) {
        QDir().mkpath(path);
    }
#ifdef _WIN32
    path+="\\recent.txt";
#else
    path+="/recent";
#endif
    filePath = path;

    QFile file(filePath);
    if (file.open(QFile::ReadWrite)) {
        QTextStream reader(&file);
        while (!reader.atEnd()) {
            items->push_back(reader.readLine());
        }
        file.close();
    }
}

void Recent::addRecentItem(QString item) {
    if (items->size()>10) {
        for (int i = 10; i<items->size(); i++) {
            items->removeAt(i);
        }
    }
    if (items->size()==10) {
        items->removeFirst();
    }
    items->push_back(item);
    Recent::write();
    FileMenu::recentMenu->loadEntries();
}

QStringList *Recent::allItems() {
    return items;
}

void Recent::write() {
    QFile file(filePath);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writer(&file);
        for (int i = 0; i<items->size(); i++) {
            writer << items->at(i)+"\n";
        }
        file.resize(writer.pos());
        file.close();
    }
}

void Recent::clearAll() {
    items->clear();
}

QString Recent::recentFilePath() {
    return filePath;
}
