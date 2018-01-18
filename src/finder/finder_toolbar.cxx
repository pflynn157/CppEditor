// Copyright 2017-2018 Patrick Flynn
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
#include "finder_toolbar.hh"
#include "finder.hh"
#include "../lang/lang-parser.hh"
#include "../icon.hh"

FinderToolbar::FinderToolbar() {
    find = new QToolButton;
    findNext = new QToolButton;
    close = new QToolButton;

    find->setIcon(IconManager::getIcon("edit-find"));
    close->setIcon(IconManager::getIcon("application-exit"));

    findNext->setText(trans("Find Next"));
    
    find->setToolTip(trans("Find"));
    close->setToolTip(trans("Close"));

    connect(find,&QToolButton::clicked,this,&FinderToolbar::findSlot);
    connect(findNext,&QToolButton::clicked,this,&FinderToolbar::findNextSlot);
    connect(close,&QToolButton::clicked,this,&FinderToolbar::closeSlot);

    entry = new QLineEdit;
    entry->setStyleSheet("background-color:white;");

    this->addWidget(find);
    this->addWidget(findNext);
    this->addWidget(entry);
    this->addWidget(close);
}

FinderToolbar::~FinderToolbar() {
    delete find;
    delete findNext;
    delete entry;
    delete close;
}

void FinderToolbar::contextMenuEvent(QContextMenuEvent *event) {
}

void FinderToolbar::findSlot() {
    TextFinder::clear();
    TextFinder::findText(entry->text());
}

void FinderToolbar::findNextSlot() {
    TextFinder::findNext(entry->text());
}

void FinderToolbar::closeSlot() {
    TextFinder::clear();
    this->setVisible(false);
}
