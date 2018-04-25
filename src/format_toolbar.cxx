// Copyright 2018 Patrick Flynn
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
#include "format_toolbar.hh"
#include "icon.hh"
#include "tabpane.hh"

FormatToolbar::FormatToolbar()
    : bold(new QToolButton),
      italic(new QToolButton),
      underline(new QToolButton)
{
    this->setMovable(false);
    this->setContextMenuPolicy(Qt::PreventContextMenu);
    this->setStyleSheet("padding:0px");

    bold->setIcon(IconManager::getIcon("format-text-bold"));
    italic->setIcon(IconManager::getIcon("format-text-italic"));
    underline->setIcon(IconManager::getIcon("format-text-underline"));

    bold->setCheckable(true);
    italic->setCheckable(true);
    underline->setCheckable(true);

    connect(bold,&QToolButton::clicked,this,&FormatToolbar::onBoldClicked);
    connect(italic,&QToolButton::clicked,this,&FormatToolbar::onItalicClicked);
    connect(underline,&QToolButton::clicked,this,&FormatToolbar::onUnderlineClicked);

    this->addWidget(bold);
    this->addWidget(italic);
    this->addWidget(underline);
}

FormatToolbar::~FormatToolbar() {
    delete bold;
    delete italic;
    delete underline;
}

void FormatToolbar::onBoldClicked() {
    if (bold->isChecked()) {
        TabPane::currentEditor()->setFontWeight(QFont::Bold);
    } else {
        TabPane::currentEditor()->setFontWeight(QFont::Normal);
    }
}

void FormatToolbar::onItalicClicked() {
    TabPane::currentEditor()->setFontItalic(italic->isChecked());
}

void FormatToolbar::onUnderlineClicked() {
    TabPane::currentEditor()->setFontUnderline(underline->isChecked());
}
