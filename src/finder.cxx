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
#include <QTextDocument>
#include <QTextCursor>
#include <QTextCharFormat>

#include "finder.hh"
#include "tabpane.hh"

FinderDialog::FinderDialog() 
	: layout(new QVBoxLayout),
	toolbar(new QToolBar),
	find(new QPushButton),
	findNext(new QPushButton),
	entry(new QLineEdit),
    output(new QTextEdit),
    close(new QPushButton)
{
    this->setWindowTitle("Find Text");
	this->setFixedSize(650,450);
	this->setLayout(layout);
	
    find->setText("Find");
    findNext->setText("Find Next");
    close->setText("Close");
	
	toolbar->addWidget(find);
	toolbar->addWidget(findNext);
	toolbar->addWidget(entry);
	
	output->setReadOnly(true);
	output->setText(TabPane::currentTabText());
	
	layout->addWidget(toolbar);
	layout->addWidget(output);
    layout->addWidget(close);

    connect(find,&QPushButton::clicked,this,&FinderDialog::onFindClicked);
    connect(findNext,&QPushButton::clicked,this,&FinderDialog::onFindNextClicked);
    connect(close,&QPushButton::clicked,this,&QDialog::close);

    count = 0;
    current = 0;
}

FinderDialog::~FinderDialog() {
	delete layout;
	delete entry;
	delete output;
    delete close;
}

void FinderDialog::onFindClicked() {
    findText(entry->text());
}

void FinderDialog::onFindNextClicked() {
    findNextTxt(entry->text());
}

void FinderDialog::findText(QString phrase, int no) {
    int c = 0;
    QTextDocument *doc = output->document();
    QTextCursor findCursor(doc);
    QTextCursor cursor(doc);

    doc->undo();
    cursor.beginEditBlock();

    QTextCharFormat format;
    format = QTextCharFormat(findCursor.charFormat());
    format.setBackground(Qt::yellow);

    while ((!findCursor.isNull())&&(!findCursor.atEnd())) {
        findCursor = doc->find(phrase,findCursor,QTextDocument::FindWholeWords);
        if (!findCursor.isNull()) {
            findCursor.movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor);
            findCursor.mergeCharFormat(format);
            c++;
            if (no==-1) {
                if (c==1) {
                    QTextCharFormat f = findCursor.charFormat();
                    f.setBackground(Qt::lightGray);
                    findCursor.mergeCharFormat(f);
                }
            } else {
                if (c==no) {
                    QTextCharFormat f = findCursor.charFormat();
                    f.setBackground(Qt::lightGray);
                    findCursor.mergeCharFormat(f);
                }
            }
        }
    }

    count = c;
    if (no==-1) {
        current = 1;
    }

    cursor.endEditBlock();
}

void FinderDialog::findText(QString phrase) {
    findText(phrase,-1);
}

void FinderDialog::findNextTxt(QString phrase) {
    int c = current;
    output->document()->undo();
    c++;
    if (c>count) {
        c = 1;
    }
    findText(phrase,c);
    current = c;
}
