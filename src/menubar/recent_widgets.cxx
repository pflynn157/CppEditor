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
#include <QStringList>
#include <QFile>
#include <QString>

#include "recent_widgets.hpp"
#include "../window.hpp"
#include "../global/recent.hpp"

RecentAction::RecentAction(QString title, QMenu *parent) : QAction(title,parent) {
    path = title;
    connect(this,&QAction::triggered,this,&RecentAction::onClicked);
}

void RecentAction::onClicked() {
    Window::addFile(path);
    Recent::addRecentItem(path);
}

RecentMenu::RecentMenu() {
    this->setTitle("Recent");
    loadEntries();
}

RecentMenu::~RecentMenu() {
    delete clearItems;
}

void RecentMenu::loadEntries() {
    this->clear();
    clearItems = new QAction("Clear List",this);
    connect(clearItems,&QAction::triggered,this,&RecentMenu::onClearItemsClicked);
    this->addAction(clearItems);
    this->addSeparator();

    QStringList *items = Recent::allItems();
    if (items->size()==0) {
        QAction *action = new QAction("None",this);
        action->setEnabled(false);
        this->addAction(action);
    } else {
        QStringList *update = new QStringList;
        for (int i = 0; i<items->size(); i++) {
            update->push_front(items->at(i));
        }
        for (int i = 0; i<update->size(); i++) {
            RecentAction *action = new RecentAction(update->at(i),this);
            this->addAction(action);
        }
    }
}

void RecentMenu::onClearItemsClicked() {
    QString path = Recent::recentFilePath();
    QFile file(path);
    if (file.exists()) {
        file.remove();
        Recent::clearAll();
        loadEntries();
    }
}
