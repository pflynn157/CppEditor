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
#include <QFileInfo>
#include <QDir>

#include "project_tree.hh"
#include "../window.hh"

ProjectTree::ProjectTree() {
    this->setHeaderLabel("Project");
    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
}

void ProjectTree::setFilePath(QString path) {
    filePath = path;
    if (!filePath.endsWith("/")) {
        filePath+="/";
    }
    
    loadTreeData(filePath, nullptr);
}

QString ProjectTree::getFilePath() {
    return filePath;
}

void ProjectTree::loadTreeData(QString path, QTreeWidgetItem *parent) {
    this->clear();

    QStringList entries = QDir(path).entryList();
    QList<QTreeWidgetItem *> items;
    
    if (!path.endsWith("/")) {
        path+="/";
    }
    
    for (int i = 0; i<entries.size(); i++) {
        if ((entries.at(i)==".")||(entries.at(i)=="..")) {
            continue;
        }
        
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0,QFileInfo(entries.at(i)).fileName());
        
        if (QFileInfo(path+entries.at(i)).isDir()) {
            item->setIcon(0,QIcon::fromTheme("inode-directory",QPixmap(":/icons/inode-directory.png")));
            loadTreeData(path+entries.at(i),item);
        } else {
            item->setIcon(0,QIcon::fromTheme("text-x-generic",QPixmap(":/icons/text-x-generic.png")));
        }
        
        if (parent == nullptr)
            items.push_back(item);
        else
            parent->addChild(item);
    }
    
    this->insertTopLevelItems(0,items);
}

void ProjectTree::onItemDoubleClicked(QTreeWidgetItem *item, int col) {
    QTreeWidgetItem *parent = item->parent();
    QString path = "";
    
    while (parent != nullptr) {
        path = parent->text(col) + "/" + path;
        parent = parent->parent();
    }
    path += item->text(col);
    path = filePath + path;

    if (QFileInfo(path).isDir()) {
        setFilePath(path);
    } else {
        Window::addFile(path);
    }
}
