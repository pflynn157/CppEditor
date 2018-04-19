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
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QVariant>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#ifdef _WIN32
#include <settings.hh>
#else
#include <cpplib/settings.hh>
#endif

#include "editor_page.hh"
#include "../tabpane.hh"
#include "../editor.hh"

using namespace CppLib;

EditorPage::EditorPage() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    subLayout = new QVBoxLayout;
    subLayout->setContentsMargins(0,0,0,0);
    subWidget = new QFrame;
    subWidget->setLayout(subLayout);
    layout->addWidget(subWidget,0,Qt::AlignTop);

    //Font settings
    QFrame *fontWidget = new QFrame;
    QHBoxLayout *fontLayout = new QHBoxLayout;
    fontWidget->setLayout(fontLayout);
    subLayout->addWidget(fontWidget);

    QLabel *fontLabel = new QLabel("Choose font for current page: ");
    fontLayout->addWidget(fontLabel);

    QPushButton *chooseFontButton = new QPushButton("Choose");
    connect(chooseFontButton,&QPushButton::clicked,this,&EditorPage::onChooseFontClicked);
    fontLayout->addWidget(chooseFontButton);

    //Line highlighter color settings
    QFrame *lineColorWidget = new QFrame;
    QHBoxLayout *lineColorLayout = new QHBoxLayout;
    lineColorWidget->setLayout(lineColorLayout);
    subLayout->addWidget(lineColorWidget);

    QLabel *lineColorLabel = new QLabel("Choose color for current line highlighter: ");
    lineColorLayout->addWidget(lineColorLabel);

    currentColor = new QLineEdit;
    currentColor->setReadOnly(true);
    currentColor->setStyleSheet("background-color: "+Settings::getSetting("editor/ine_color","#d9d9d9")+";");
    currentColor->setFixedWidth(50);
    lineColorLayout->addWidget(currentColor);

    QPushButton *lineColorButton = new QPushButton("Choose");
    connect(lineColorButton,&QPushButton::clicked,this,&EditorPage::onChooseLineHighlighterClicked);
    lineColorLayout->addWidget(lineColorButton);

    //Autoindent settings
    QFrame *aiWidget = new QFrame;
    QHBoxLayout *aiLayout = new QHBoxLayout;
    aiWidget->setLayout(aiLayout);
    subLayout->addWidget(aiWidget);

    QCheckBox *aiCheckBox = new QCheckBox("Auto indent");
    aiCheckBox->setChecked(QVariant(Settings::getSetting("editor/autoindent","true")).toBool());
    connect(aiCheckBox,SIGNAL(clicked(bool)),this,SLOT(onAutoIndentClicked(bool)));
    aiLayout->addWidget(aiCheckBox);
}

EditorPage::~EditorPage() {
    delete layout;
    delete subLayout;
    delete subWidget;
}

void EditorPage::onChooseFontClicked() {
    QFontDialog dialog;
    dialog.setCurrentFont(TabPane::currentWidget()->font());
    if (dialog.exec()) {
        TabPane::currentWidget()->setFont(dialog.selectedFont());
    }
}

void EditorPage::onChooseLineHighlighterClicked() {
    QColor color = QColorDialog::getColor(QColor("#d9d9d9"));
    currentColor->setStyleSheet("background-color: "+color.name()+";");
    Settings::writeSetting("editor/line_color",color.name());
    Editor::updateSettings();
}

void EditorPage::onAutoIndentClicked(bool ai) {
    if (ai) {
        Settings::writeSetting("editor/autoindent","true");
    } else {
        Settings::writeSetting("editor/autoindent","false");
    }
    Editor::updateSettings();
}
