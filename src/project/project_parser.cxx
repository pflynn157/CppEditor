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
#include <QTreeWidgetItem>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QInputDialog>
#include <QIcon>

#include "project_parser.hh"
#include "../tinyxml2.h"

using namespace tinyxml2;

QString ProjectParser::filePath;

void ProjectParser::PopulateTree(QString file, ProjectTree *tree) {
    tree->clear();
    filePath = file;
    tree->setCompletePath(filePath);
    tree->setFilePath(QFileInfo(filePath).absoluteDir().path());
    GetTitle(file,tree);
    LoadFiles(file,tree);
    LoadSrc(file,tree);
}

void ProjectParser::NewProject(QString path, ProjectTree *tree) {
    if (!QFile(path).exists()) {
        QFile file(path);
        if (file.open(QFile::ReadWrite)) {
            file.close();
        }
    }
    XMLDocument *doc = new XMLDocument;
    doc->LoadFile(path.toStdString().c_str());
    XMLElement *root = doc->FirstChildElement("project");
    if (root==nullptr) {
        root = doc->NewElement("project");
        doc->InsertFirstChild(root);
        QInputDialog input;
        input.setTextValue("Untitled Project");
        input.setLabelText("Enter a name for your project:");
        input.setWindowTitle("Project Name");
        input.setInputMode(QInputDialog::TextInput);
        bool exec = input.exec();
        if ((exec)&&(!input.textValue().isEmpty())) {
            QString val = input.textValue();
            root->SetAttribute("title",val.toStdString().c_str());
        }
    }
    doc->SaveFile(path.toStdString().c_str());
    PopulateTree(path,tree);
}

void ProjectParser::AddItem(QString path, QString tag, ProjectTree *tree) {
    try {
        tree->clear();
        QString projectPath = tree->getCompletePath();
        XMLDocument *doc = new XMLDocument;
        doc->LoadFile(projectPath.toStdString().c_str());
        XMLElement *root = doc->FirstChildElement("project");
        XMLElement *fileNode = doc->NewElement(tag.toStdString().c_str());
        fileNode->SetText(QString(QFileInfo(path).fileName()).toStdString().c_str());
        root->LinkEndChild(fileNode);
        doc->SaveFile(projectPath.toStdString().c_str());
        PopulateTree(projectPath,tree);
    } catch (std::exception &) {
        return;
    }
}

void ProjectParser::SetTitle(QString title, ProjectTree *tree) {
    QString file = tree->getCompletePath();
    XMLDocument *doc = new XMLDocument;
    doc->LoadFile(file.toStdString().c_str());
    XMLElement *root = doc->FirstChildElement("project");
    if (root==nullptr) {
        return;
    }
    root->SetAttribute("title",title.toStdString().c_str());
    doc->SaveFile(file.toStdString().c_str());
    PopulateTree(file,tree);
}

void ProjectParser::GetTitle(QString file, QTreeWidget *tree) {
    QString title = "Untitled Project";
    tree->setHeaderLabel(title);
    XMLDocument *doc = new XMLDocument;
    doc->LoadFile(file.toStdString().c_str());
    XMLElement *root = doc->FirstChildElement("project");
    if (root==nullptr) {
        return;
    }
    title = QString(root->Attribute("title"));
    tree->setHeaderLabel(title);
}

void ProjectParser::LoadFiles(QString file, QTreeWidget *tree) {
    try {
        QStringList *files = new QStringList;
        XMLDocument *doc = new XMLDocument;
        doc->LoadFile(file.toStdString().c_str());
        XMLElement *root = doc->FirstChildElement("project");
        if (root==nullptr) {
            return;
        }
        XMLElement *current = root->FirstChildElement("file");
        if (current==nullptr) {
            return;
        }
        files->push_back(QString(current->GetText()));
        XMLElement *lastElement = current;
        XMLElement *previous;
        while (lastElement->NextSiblingElement("file")!=nullptr) {
            previous = lastElement;
            lastElement = lastElement->NextSiblingElement("file");
            if (lastElement==nullptr) {
                return;
            }
            QString text = QString(lastElement->GetText());
            files->push_back(text);
        }
        QList<QTreeWidgetItem *> fileItems;
        for (int i = 0; i<files->size(); i++) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0,files->at(i));
            item->setIcon(0,QIcon::fromTheme("text-x-generic",QPixmap(":/icons/text-x-generic.png")));
            fileItems.push_back(item);
        }
        tree->insertTopLevelItems(0,fileItems);
    } catch (std::exception &) {
        return;
    }
}

void ProjectParser::LoadSrc(QString file, ProjectTree *tree) {
    try {
        QStringList *dirs = new QStringList;
        XMLDocument *doc = new XMLDocument;
        doc->LoadFile(file.toStdString().c_str());
        XMLElement *root = doc->FirstChildElement("project");
        XMLElement *base = root->FirstChildElement("src");
        if (base!=nullptr) {
            dirs->push_back(QString(base->GetText()));
        } else {
            return;
        }
        if (base->NextSiblingElement("src")!=nullptr) {
            XMLElement *lastBase;
            while (base->NextSiblingElement("src")!=nullptr) {
                lastBase = base;
                if (lastBase==nullptr) {
                    return;
                }
                base = base->NextSiblingElement("src");
                if (base==nullptr) {
                    return;
                }
                dirs->push_back(QString(base->GetText()));
            }
        }
        QList<QTreeWidgetItem *> dirItems;
        for (int i = 0; i<dirs->size(); i++) {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0,dirs->at(i));
            item->setIcon(0,QIcon::fromTheme("inode-directory",QPixmap(":/icons/inode-directory.png")));
            AddChildren(tree->getFilePath()+dirs->at(i),item);
            dirItems.push_back(item);
        }
        tree->insertTopLevelItems(0,dirItems);
    } catch (std::exception &) {
        return;
    }
}

void ProjectParser::AddChildren(QString path, QTreeWidgetItem *parent) {
    QStringList entries = QDir(path).entryList();
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
            parent->addChild(item);
            AddChildren(path+entries.at(i),item);
        } else {
            item->setIcon(0,QIcon::fromTheme("text-x-generic",QPixmap(":/icons/text-x-generic.png")));
            parent->addChild(item);
        }
    }
}
