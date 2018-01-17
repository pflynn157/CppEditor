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
#include <iostream>
#include <QMessageBox>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "lang-dialog.hh"
#include "lang-manager.hh"
#include "lang-parser.hh"

using namespace CppLib;

LangDialog::LangDialog() {
    this->setWindowTitle(trans("Change Application Language"));
    this->setFixedSize(300,150);

    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(mainLayout);

    sub1 = new QFrame;
    layout1 = new QHBoxLayout;
    sub1->setLayout(layout1);
    mainLayout->addWidget(sub1);

    sub2 = new QFrame;
    layout2 = new QHBoxLayout;
    sub2->setLayout(layout2);
    mainLayout->addWidget(sub2);

    label = new QLabel(trans("Choose Language:"));
    layout1->addWidget(label);

    langBox = new QComboBox;
    QStringList *langs = LangManager::allLangs();
    for (int i = 0; i<langs->size(); i++) {
        langBox->addItem(langs->at(i));
    }
    langBox->setCurrentText(LangManager::langName);
    layout1->addWidget(langBox);

    submit = new QPushButton(trans("Submit"));
    connect(submit,&QPushButton::clicked,this,&LangDialog::onSubmitClicked);
    layout2->addWidget(submit);
}

LangDialog::~LangDialog() {
    delete mainLayout;
    delete layout1;
    delete layout2;
    delete sub1;
    delete sub2;
}

void LangDialog::onSubmitClicked() {
    QString langName = langBox->currentText();
    QString langPath = LangManager::getFile(langBox->currentText());
    Settings::writeSetting("language/name",langName);
    Settings::writeSetting("language/path",langPath);
    this->close();

    QMessageBox msg;
    msg.setWindowTitle(trans("Notice"));
    msg.setText(trans("lang-change-msg"));
    msg.setIcon(QMessageBox::Warning);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
