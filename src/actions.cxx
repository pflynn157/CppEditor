// Copyright 2020 Patrick Flynn
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
#include <QKeySequence>

#include <actions.hpp>
#include <icon.hpp>
#include <global/slots.hpp>

Action::Action(QString name, QString iconName, QObject *parent) : QAction(name,parent) {
    this->setIcon(IconManager::getIcon(iconName));
}

CopyAction::CopyAction(QObject *parent) : Action("Copy","edit-copy",parent) {
    this->setShortcut(QKeySequence::Copy);
    connect(this,&QAction::triggered,new Slots,&Slots::copySlot);
}

CutAction::CutAction(QObject *parent) : Action("Cut","edit-cut",parent) {
    this->setShortcut(QKeySequence::Cut);
    connect(this,&QAction::triggered,new Slots,&Slots::cutSlot);
}

PasteAction::PasteAction(QObject *parent) : Action("Paste","edit-paste",parent) {
    this->setShortcut(QKeySequence::Paste);
    connect(this,&QAction::triggered,new Slots,&Slots::pasteSlot);
}

RedoAction::RedoAction(QObject *parent) : Action("Redo","edit-redo",parent) {
    this->setShortcut(QKeySequence::Redo);
    connect(this,&QAction::triggered,new Slots,&Slots::redoSlot);
}

SelectAllAction::SelectAllAction(QObject *parent) : Action("Select All","edit-select-all",parent) {
    this->setShortcut(QKeySequence::SelectAll);
    connect(this,&QAction::triggered,new Slots,&Slots::selectAllSlot);
}

UndoAction::UndoAction(QObject *parent) : Action("Undo","edit-undo",parent) {
    this->setShortcut(QKeySequence::Undo);
    connect(this,&QAction::triggered,new Slots,&Slots::undoSlot);
}

