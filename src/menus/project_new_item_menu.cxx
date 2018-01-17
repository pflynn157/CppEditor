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
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>

#include "project_new_item_menu.hh"
#include "../tabpane.hh"
#include "../editor.hh"
#include "../project/project_parser.hh"

ProjectNewItemMenu::ProjectNewItemMenu(ProjectTree *parentTree) {
    parent = parentTree;

    newProject = new QAction("New Project",this);
    newSrc = new QAction("New Source Folder",this);
    newItem = new QAction("New Item",this);

    newSrc->setEnabled(false);
    newItem->setEnabled(false);

    connect(newProject,&QAction::triggered,this,&ProjectNewItemMenu::onNewProjectClicked);
    connect(newSrc,&QAction::triggered,this,&ProjectNewItemMenu::onSrcItemClicked);
    connect(newItem,&QAction::triggered,this,&ProjectNewItemMenu::onNewItemClicked);

    this->addAction(newProject);
    this->addAction(newSrc);
    this->addAction(newItem);
}

ProjectNewItemMenu::~ProjectNewItemMenu() {
    delete newProject;
    delete newSrc;
    delete newItem;
}

void ProjectNewItemMenu::setFile(QString file) {
    filePath = file;
    newSrc->setEnabled(true);
    newItem->setEnabled(true);
}

void ProjectNewItemMenu::onNewProjectClicked() {
    QFileDialog dialog;
    dialog.setWindowTitle("Create Project");
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec()) {
        QStringList selected = dialog.selectedFiles();
        if (selected.size()==0) {
            return;
        }
        ProjectParser::NewProject(selected.at(0),parent);
        this->setFile(selected.at(0));
    }
}

void ProjectNewItemMenu::onSrcItemClicked() {
    QFileDialog dialog;
    dialog.setWindowTitle("Choose Folder");
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    if (dialog.exec()) {
        QStringList selected = dialog.selectedFiles();
        if (selected.size()==0) {
            return;
        }
        ProjectParser::AddItem(selected.at(0),"src",parent);
    }
}

void ProjectNewItemMenu::onNewItemClicked() {
    QMessageBox msg;
    msg.setWindowTitle("Choose File");
    msg.setText("Do you wish to include the current tab?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    int ret = msg.exec();
    QString selectedFile = "";
    if (ret==QMessageBox::Yes) {
        selectedFile = TabPane::currentWidget()->path();
    } else {
        QFileDialog dialog;
        dialog.setWindowTitle("Choose File");
        dialog.setAcceptMode(QFileDialog::AcceptOpen);
        if (dialog.exec()) {
            QStringList selected = dialog.selectedFiles();
            if (selected.size()==0) {
                return;
            }
            selectedFile = selected.at(0);
        } else {
            return;
        }
    }
    ProjectParser::AddItem(selectedFile,"file",parent);
}
