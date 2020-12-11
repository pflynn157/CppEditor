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
#include <QColorDialog>

#include "insertmenu.hpp"
#include "../window.hpp"
#include "../global/file_actions.hpp"
#include "../tabpane.hpp"
#include "../editor.hpp"

InsertMenu::InsertMenu(QMainWindow *parent) {
    window = parent;
    this->setTitle("Insert");

    datePicker = new QAction("Insert a date",this);
    loremIpsum = new QAction("Insert Lorem Ipsum text",this);
    colorDialog = new QAction("Insert a color",this);

    connect(datePicker,&QAction::triggered,this,&InsertMenu::onDatePickerClicked);
    connect(loremIpsum,&QAction::triggered,this,&InsertMenu::onLoremIpsumClicked);
    connect(colorDialog,&QAction::triggered,this,&InsertMenu::onColorDialogClicked);

    this->addAction(datePicker);
    this->addAction(loremIpsum);
    this->addAction(colorDialog);
}

InsertMenu::~InsertMenu() {
    delete datePicker;
    delete loremIpsum;
    delete colorDialog;
}

void InsertMenu::onDatePickerClicked() {
    Window::dispalyDateSelector();
}

void InsertMenu::onLoremIpsumClicked() {
    LoremIpsumDialog dialog;
    dialog.exec();
}

void InsertMenu::onColorDialogClicked() {
    QColorDialog dialog;
    if (dialog.exec()) {
        QColor color = dialog.selectedColor();
        TextEdit *edit = TabPane::currentEditor();
        edit->insertPlainText(color.name());
    }
}

//The LoremIpsum dialog
LoremIpsumDialog::LoremIpsumDialog()
    : centerWidget(new QFrame),
      centerLayout(new QVBoxLayout),
      label(new QLabel),
      edit(new QTextEdit),
      buttons(new QDialogButtonBox)
{
    this->setWindowTitle("Insert Lorem Ipsum Text");
    this->resize(500,400);
    this->setLayout(centerLayout);

    label->setText("Choose the text to be inserted:");

    QString text = FileActions::fileContents(":/rsc/lorem_ipsum.txt");
    edit->setText(text);

    buttons->addButton(QDialogButtonBox::Cancel);
    buttons->addButton(QDialogButtonBox::Ok);

    connect(buttons,&QDialogButtonBox::accepted,this,&LoremIpsumDialog::onOkClicked);
    connect(buttons,&QDialogButtonBox::rejected,this,&LoremIpsumDialog::onCancelClicked);

    centerLayout->addWidget(label,0,Qt::AlignTop);
    centerLayout->addWidget(edit);
    centerLayout->addWidget(buttons);
}

LoremIpsumDialog::~LoremIpsumDialog() {
    delete centerWidget;
    delete centerLayout;
    delete label;
    delete edit;
    delete buttons;
}

void LoremIpsumDialog::onOkClicked() {
    QString text = edit->toPlainText();
    TextEdit *editor = TabPane::currentEditor();
    editor->insertPlainText(text);
    this->close();
}

void LoremIpsumDialog::onCancelClicked() {
    this->close();
}
