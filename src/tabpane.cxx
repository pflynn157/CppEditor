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
#include <QFileInfo>
#include <QFont>
#include <QMessageBox>

#include "tabpane.hpp"
#include "editor.hpp"
#include "window.hpp"
#include "main_toolbar.hpp"
#include "global.hpp"

CppMessageWidget *TabPane::rootStatus, *TabPane::settingsSaved, *TabPane::buttonHidden;
QTabWidget *TabPane::tabs;
Window *TabPane::window;

TabPane::TabPane(Window *parent) {
    window = parent;

    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    rootStatus = new CppMessageWidget("You are running this program as root! Be careful!");
    rootStatus->setCloseButtonVisible(false);
    rootStatus->hide();
    layout->addWidget(rootStatus);

    settingsSaved = new CppMessageWidget("You must restart CppEditor for these changes to take effect.");
    settingsSaved->hide();
    layout->addWidget(settingsSaved);

    buttonHidden = new CppMessageWidget;
    buttonHidden->hide();
    layout->addWidget(buttonHidden);

    tabs = new QTabWidget();
    layout->addWidget(tabs);

    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    addNewUntitledTab();

    Window::setStatusBarPath(currentWidget()->path());
    Window::setStatusBarModified(currentWidget()->isModified());

    connect(tabs,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabClosed(int)));
    connect(tabs,&QTabWidget::currentChanged,this,&TabPane::onTabChanged);
}

TabPane::~TabPane() {
    delete layout;
}

void TabPane::addNewTab(QString path) {
    int count = tabs->count();
    tabs->addTab(new Editor(path, window),QFileInfo(path).fileName());
    tabs->setCurrentIndex(count);
    window->setTitle(path);
}

void TabPane::addNewUntitledTab() {
    int count = tabs->count();
    Editor *edit = new Editor("untitled", window);
    tabs->addTab(edit,"untitled");
    tabs->setCurrentIndex(count);
    window->setTitle("untitled");
}

Editor *TabPane::currentWidget() {
    return static_cast<Editor *>(tabs->currentWidget());
}

TextEdit *TabPane::currentEditor() {
    return currentWidget()->editorWidget();
}

Editor *TabPane::widgetAt(int index) {
    return static_cast<Editor *>(tabs->widget(index));
}

TextEdit *TabPane::editorAt(int index) {
    return widgetAt(index)->editorWidget();
}

void TabPane::setCurrentTabPath(QString path) {
    currentWidget()->setPath(path);
    Window::setStatusBarPath(path);
    window->setTitle(path);
}

void TabPane::setCurrentTabText(QString text) {
    currentWidget()->setEditorText(text);
}

QString TabPane::currentTabText() {
    return currentEditor()->toPlainText();
}

void TabPane::setCurrentTabTitle(QString title) {
    tabs->setTabText(tabs->currentIndex(),title);
}

void TabPane::onTabClosed(int index) {
    if (tabs->count()==1) {
        addNewUntitledTab();
    }
    Editor *edit = TabPane::widgetAt(index);
    if (edit->isModified()) {
        QMessageBox msg;
        msg.setWindowTitle("Warning");
        msg.setIcon(QMessageBox::Warning);
        msg.setText("You are about to close an unsaved document.\n"
                    "Do you wish to continue?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msg.exec();
        if (ret==QMessageBox::Yes) {
            delete edit;
        }
    } else {
        delete edit;
    }
}

void TabPane::onTabChanged() {
    Window::setStatusBarPath(currentWidget()->path());
    Window::setStatusBarModified(currentWidget()->isModified());
    
    auto toolbar = window->getMainToolbar();
    toolbar->setFontSize(currentWidget()->font().pointSize());
    toolbar->setSyntaxName(currentWidget()->currentID());

    window->setTitle(currentWidget()->path());
}

