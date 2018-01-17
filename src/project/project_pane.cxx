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
#include <QIcon>
#include <QFileDialog>
#include <QInputDialog>

#include "project_pane.hh"
#include "project_parser.hh"

ProjectPane::ProjectPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    projectTree = new ProjectTree;
    layout->addWidget(projectTree);

    openProject = new QToolButton;
    newItem = new QToolButton;
    editProject = new QToolButton;

    newItem->setPopupMode(QToolButton::InstantPopup);
    editProject->setEnabled(false);

    openProject->setIcon(QIcon::fromTheme("document-open",QPixmap(":/icons/document-open.png")));
    newItem->setIcon(QIcon::fromTheme("document-new",QPixmap(":/icons/document-new.png")));
    editProject->setIcon(QIcon::fromTheme("document-edit",QPixmap(":/icons/document-edit.png")));

    connect(openProject,&QToolButton::clicked,this,&ProjectPane::onOpenProjectClicked);
    connect(editProject,&QToolButton::clicked,this,&ProjectPane::onEditProjectClicked);

    newItemMenu = new ProjectNewItemMenu(projectTree);
    newItem->setMenu(newItemMenu);

    toolbar->addWidget(openProject);
    toolbar->addWidget(newItem);
    toolbar->addWidget(editProject);
}

ProjectPane::~ProjectPane() {
    delete layout;
}

void ProjectPane::mousePressEvent(QMouseEvent *event) {

}

void ProjectPane::onOpenProjectClicked() {
    QFileDialog dialog;
    dialog.setWindowTitle("Open Project");
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    if (dialog.exec()) {
        if (dialog.selectedFiles().size()==0) {
            return;
        }
        ProjectParser::PopulateTree(dialog.selectedFiles().at(0),projectTree);
        newItemMenu->setFile(dialog.selectedFiles().at(0));
        editProject->setEnabled(true);
    }
}

void ProjectPane::onEditProjectClicked() {
    QInputDialog dialog;
    dialog.setLabelText("Enter your project title:");
    dialog.setTextValue("Untitled Project");
    dialog.setWindowTitle("Rename Project");
    bool ok = dialog.exec();
    if ((ok)&&(!dialog.textValue().isEmpty())) {
        QString val = dialog.textValue();
        ProjectParser::SetTitle(val,projectTree);
    }
}
