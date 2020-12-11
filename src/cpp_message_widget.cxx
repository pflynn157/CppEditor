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
#include <QPropertyAnimation>

#include "cpp_message_widget.hpp"
#include "global/file_actions.hpp"

CppMessageWidget::CppMessageWidget() : CppMessageWidget("") { }

CppMessageWidget::CppMessageWidget(QString text) {
    layout = new QHBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    label = new QLabel(text);
    layout->addWidget(label,0,Qt::AlignLeft);

    close = new QToolButton;
    close->setText("X");
    connect(close,&QToolButton::clicked,this,&CppMessageWidget::onCloseClicked);
    layout->addWidget(close,0,Qt::AlignRight);

    this->setStyleSheet(FileActions::fileContents(":/rsc/message_widget.css"));

    h = this->height();
}

CppMessageWidget::~CppMessageWidget() {
    delete layout;
    delete label;
    delete close;
}

void CppMessageWidget::animatedShow() {
    this->show();
    QPropertyAnimation *animation = new QPropertyAnimation(this,"maximumHeight");
    animation->setDuration(2000);
    animation->setStartValue(0);
    animation->setEndValue(h);
    animation->start();
}

void CppMessageWidget::setCloseButtonVisible(bool show) {
    if (show) {
        close->show();
    } else {
        close->hide();
    }
}

void CppMessageWidget::setText(QString text) {
    label->setText(text);
}

void CppMessageWidget::onCloseClicked() {
    this->hide();
}
