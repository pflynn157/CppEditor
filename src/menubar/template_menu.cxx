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
#include <QStringList>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>

#include "template_menu.hh"
#include "../template/template.hh"
#include "../tabpane.hh"
#include "../window.hh"
#include "../global/file_actions.hh"
#include "../lang/lang-parser.hh"

TemplateAction::TemplateAction(QString path, QMenu *parent) : QAction(path,parent) {
    name = path;
    connect(this,&QAction::triggered,this,&TemplateAction::onClick);
}

void TemplateAction::onClick() {
    TabPane::currentWidget()->insertPlainText(FileActions::fileContents(Template::templatePath()+name));
}

TemplateMenu::TemplateMenu() {
    this->setTitle(trans("Templates"));
    templateList = new QMenu(trans("Templates"));
    this->addMenu(templateList);
    loadEntries();

    saveAsTemplate = new QAction(trans("Save as template"),this);
    connect(saveAsTemplate,&QAction::triggered,this,&TemplateMenu::saveAsTemplateClicked);
    this->addAction(saveAsTemplate);
}

TemplateMenu::~TemplateMenu() {
    delete templateList;
    delete saveAsTemplate;
}

void TemplateMenu::loadEntries() {
    templateList->clear();
    QStringList *items = Template::getAllTemplates();
    if (items->size()==0) {
        QAction *none = new QAction(trans("None"),this);
        none->setEnabled(false);
        templateList->addAction(none);
    } else {
        for (int i = 0; i<items->size(); i++) {
            TemplateAction *action = new TemplateAction(items->at(i),this);
            templateList->addAction(action);
        }
    }
}

void TemplateMenu::saveAsTemplateClicked() {
    QString infoText = "Do you wish to save the text in the current tab as a template?\n\n"
                       "If the text is part of a file, the file will not be affected; the text will simply be copied.\n"
                       "If the text is part of an untitled file, the text will be saved to a template, but you will be "
                       "responsible for saving the file if you so wish.\n\n"
                       "Enter the name for your template below:";
    QInputDialog dialog;
    dialog.setWindowTitle("Save As Template");
    dialog.setLabelText(infoText);
    if (dialog.exec()) {
        QString dialogText = dialog.textValue();
        QString text = TabPane::currentTabText();
        QFile file(Template::templatePath()+dialogText);
        if (file.open(QFile::ReadWrite)) {
            QTextStream writer(&file);
            writer << text;
            file.close();
        }
    }
    Window::templateMenu->loadEntries();
}
