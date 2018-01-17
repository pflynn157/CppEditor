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
#include "console_win.hh"

ConsoleWin::ConsoleWin() {
    this->setWindowTitle("Console");

    QFrame *mainWidget = new QFrame;
    mainLayout = new QVBoxLayout;
    mainWidget->setLayout(mainLayout);
    this->setWidget(mainWidget);

    cmdWidget = new QFrame;
    sendWidget = new QFrame;

    cmdLayout = new QHBoxLayout;
    cmdLayout->setContentsMargins(0,0,0,0);

    sendLayout = new QHBoxLayout;
    sendLayout->setContentsMargins(0,0,0,0);

    cmdWidget->setLayout(cmdLayout);
    sendWidget->setLayout(sendLayout);

    start = new QPushButton("Start");
    connect(start,&QPushButton::clicked,this,&ConsoleWin::onStartClicked);

    send = new QPushButton("Send");
    connect(send,&QPushButton::clicked,this,&ConsoleWin::onSendClicked);

    cmdLine = new QLineEdit;
    cmdLine->setStyleSheet("background-color:white");

    inputLine = new QLineEdit;
    inputLine->setStyleSheet("background-color:white");

    cmdLayout->addWidget(start);
    cmdLayout->addWidget(cmdLine);

    sendLayout->addWidget(send);
    sendLayout->addWidget(inputLine);

    output = new QTextEdit;
    output->setReadOnly(true);

    mainLayout->addWidget(cmdWidget);
    mainLayout->addWidget(sendWidget);
    mainLayout->addWidget(output);
}

void ConsoleWin::onStartClicked() {
    output->setText("");
    proc = new Process(cmdLine->text().toLatin1());
    connect(proc,SIGNAL(outputReady(QString)),this,SLOT(onProcOuput(QString)));
    connect(proc,SIGNAL(processDone(int)),this,SLOT(onProcDone(int)));
}

void ConsoleWin::onSendClicked() {
    if (proc!=nullptr) {
        proc->sendInput(inputLine->text());
    }
}

void ConsoleWin::onProcOuput(QString text) {
    output->insertPlainText(text);
}

void ConsoleWin::onProcDone(int code) {
    output->insertPlainText("\n** Process Completed; Exit code: "+QString::number(code)+" **\n");
}
