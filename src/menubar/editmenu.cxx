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
#include "editmenu.hh"
#include "../window.hh"
#include "../lang/lang-parser.hh"
#include "../icon.hh"

EditMenu::EditMenu() {
    this->setTitle(trans("Edit"));

    cut = new CutAction(this);
    copy = new CopyAction(this);
    paste = new PasteAction(this);
    selectAll = new SelectAllAction(this);
    undo = new UndoAction(this);
    redo = new RedoAction(this);
    find = new QAction(IconManager::getIcon("edit-find"),trans("Find Text"),this);

    connect(find,&QAction::triggered,this,&EditMenu::onFindClicked);

    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
    this->addAction(selectAll);
    this->addSeparator();
    this->addAction(undo);
    this->addAction(redo);
    this->addSeparator();
    this->addAction(find);
}

EditMenu::~EditMenu() {
    delete cut;
    delete copy;
    delete paste;
    delete selectAll;
    delete undo;
    delete redo;
    delete find;
}

void EditMenu::onFindClicked() {

}
