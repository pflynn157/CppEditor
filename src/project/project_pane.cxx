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
#include <QIcon>
#include <QFileDialog>
#include <QInputDialog>
#include <QDir>
#include <QFile>

#include "project_pane.hpp"
#include <tabpane.hpp>
#include <editor.hpp>

ProjectPane::ProjectPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    projectTree = new ProjectTree;
    layout->addWidget(projectTree);

    goUp = new QToolButton;
    newFile = new QToolButton;
    newFolder = new QToolButton;
    refresh = new QToolButton;
    
    goUp->setIcon(QIcon::fromTheme("go-up"));
    newFile->setIcon(QIcon::fromTheme("document-new"));
    newFolder->setIcon(QIcon::fromTheme("folder-new"));
    refresh->setIcon(QIcon::fromTheme("view-refresh"));

    connect(goUp, &QToolButton::clicked, this, &ProjectPane::onGoUpClicked);
    connect(newFile, &QToolButton::clicked, this, &ProjectPane::onNewFileClicked);
    connect(newFolder, &QToolButton::clicked, this, &ProjectPane::onNewFolderClicked);
    connect(refresh, &QToolButton::clicked, this, &ProjectPane::onRefreshClicked);

    toolbar->addWidget(goUp);
    toolbar->addWidget(newFile);
    toolbar->addWidget(newFolder);
    toolbar->addWidget(refresh);
}

ProjectPane::~ProjectPane() {
    delete layout;
}

void ProjectPane::loadTree() {
    QString currentPath = projectTree->getFilePath();

    if (currentPath == "") {
        Editor *current = TabPane::widgetAt(0);
        if (current->isUntitled()) {
            currentPath = QDir::currentPath();
        } else {
        	    QString path = current->path();
        	    currentPath = QFileInfo(path).absolutePath();
        }
    }

    projectTree->setFilePath(currentPath);
}

void ProjectPane::mousePressEvent(QMouseEvent *event) {
}

void ProjectPane::onGoUpClicked() {
    QString currentPath = projectTree->getFilePath();
    QDir dir(currentPath);
    if (dir.cdUp()) currentPath = dir.absolutePath();
    projectTree->setFilePath(currentPath);
}

void ProjectPane::onNewFileClicked() {
    QString name = QInputDialog::getText(nullptr, "New File", "Enter file name:");
    
    QString currentPath = projectTree->getSelectedPath();
    
    if (!QFileInfo(currentPath).isDir()) {
        currentPath = projectTree->getFilePath();
    }
    
    currentPath += "/" + name;
    
    QFile file(currentPath);
    if (file.open(QFile::WriteOnly)) {
        file.close();
    }
    
    loadTree();
}

void ProjectPane::onNewFolderClicked() {
    QString name = QInputDialog::getText(nullptr, "New Folder", "Enter folder name:");

    QString currentPath = projectTree->getSelectedPath();
    
    if (!QFileInfo(currentPath).isDir()) {
        currentPath = projectTree->getFilePath();
    }
    
    currentPath += "/" + name;
    
    QDir().mkpath(currentPath);
    loadTree();
}

void ProjectPane::onRefreshClicked() {
    loadTree();
}
