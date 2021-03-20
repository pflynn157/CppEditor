// Copyright 2017-2018, 2020 Patrick Flynn
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
#include <QIcon>
#include <QPixmap>
#include <QCloseEvent>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QMenuBar>
#include <QFileInfo>
#include <QFile>
#include <QCheckBox>

#include <window.hpp>
#include <tabpane.hpp>
#include <main_toolbar.hpp>
#include <icon.hpp>
#include <global.hpp>
#include <global/file_actions.hpp>
#include <global/recent.hpp>

QStatusBar *Window::statusbar;
QLabel *Window::modLabel, *Window::pathLabel, *Window::lineCountLabel;
QCheckBox *Window::useTabs, *Window::intelIndent;
QSplitter *Window::centralSplitter;
ProjectPane *Window::projectPane;
DateDockWidget *Window::dateDockWidget;

Window::Window() {
    this->setWindowTitle("CppEditor");
    this->setWindowIcon(IconManager::getIcon("accessories-text-editor"));
    this->resize(800,600);
    this->showMaximized();
    
    filemenu = new FileMenu(this);
    editmenu = new EditMenu;
    insertmenu = new InsertMenu(this);
    viewmenu = new ViewMenu(this);
    helpmenu = new HelpMenu;

    this->menuBar()->setContextMenuPolicy(Qt::PreventContextMenu);
    this->menuBar()->addMenu(filemenu);
    this->menuBar()->addMenu(editmenu);
    this->menuBar()->addMenu(insertmenu);
    this->menuBar()->addMenu(viewmenu);
    this->menuBar()->addMenu(helpmenu);
    
    toolbar = new MainToolBar(this);
    toolbar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    toolbar->setFloatable(false);
    this->addToolBar(Qt::TopToolBarArea, toolbar);

    statusbar = new QStatusBar();
    statusbar->setContextMenuPolicy(Qt::PreventContextMenu);
    this->setStatusBar(statusbar);

    modLabel = new QLabel();
    pathLabel = new QLabel();
    intelIndent = new QCheckBox("Intelligent Auto-indent");
    useTabs = new QCheckBox("Use Tabs");
    lineCountLabel = new QLabel("Current Line: 1");
    
    intelIndent->setChecked(true);
    if (settings.value("editor/autoindent", "true").toBool()) {
        intelIndent->show();
    } else {
        intelIndent->hide();
    }

    statusbar->addWidget(pathLabel);
    statusbar->addWidget(modLabel);
    statusbar->addPermanentWidget(intelIndent);
    statusbar->addPermanentWidget(useTabs);
    statusbar->addPermanentWidget(lineCountLabel);

    centralSplitter = new QSplitter();
    this->setCentralWidget(centralSplitter);

    TabPane *tabs = new TabPane(this);
    
    projectPane = new ProjectPane;
    projectPane->setFixedWidth(250);
    projectPane->hide();

    centralSplitter->addWidget(projectPane);
    centralSplitter->addWidget(tabs);

    dateDockWidget = new DateDockWidget;
    dateDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    if (settings.value("subwindows/date_selector","true").toBool()) {
        dateDockWidget->hide();
    } else {
        dateDockWidget->show();
    }
    this->addDockWidget(Qt::LeftDockWidgetArea,dateDockWidget);

    connect(qApp,SIGNAL(applicationStateChanged(Qt::ApplicationState)),this,SLOT(onWindowStateChanged(Qt::ApplicationState)));
}

Window::~Window() {
    delete statusbar;
    delete centralSplitter;
    delete dateDockWidget;
    delete filemenu;
    delete editmenu;
    delete insertmenu;
    delete viewmenu;
    delete helpmenu;
}

void Window::setTitle(QString title, bool custom) {
    if (custom) {
        this->setWindowTitle(title);
        customTitle = true;
    }

    if (!customTitle) {
        QString t = title + " [CppEditor]";
        this->setWindowTitle(t);
    }
}

MainToolBar *Window::getMainToolbar() {
    return toolbar;
}

void Window::addFile(QString path) {
    int count = TabPane::tabs->count();
    bool found = false;
    
    for (int i = 0; i<count; i++) {
        QString currentPath = TabPane::widgetAt(i)->path();
        if (currentPath==path) {
            TabPane::tabs->setCurrentIndex(i);
            found = true;
            break;
        }
    }
    
    if (!found) {
        if ((TabPane::currentWidget()->isUntitled())&&(TabPane::currentWidget()->isModified()==false)) {
            TabPane::setCurrentTabPath(path);
            TabPane::setCurrentTabTitle(QFileInfo(path).fileName());
        } else {
            TabPane::addNewTab(path);
        }    
    }

    TabPane::setCurrentTabText(FileActions::fileContents(path));
    TabPane::currentWidget()->setModified(false);
}

void Window::setStatusBarModified(bool modified) {
    if (modified) {
        modLabel->setText("unsaved");
    } else {
        modLabel->setText("saved");
    }
}

void Window::setStatusBarPath(QString path) {
    pathLabel->setText(path);
}

void Window::setStatusBarLineCount(int count) {
    QString strCount = QString::number(count);
    lineCountLabel->setText("Current Line: "+strCount);
}

bool Window::checkSave() {
    bool found = false;
    QStringList items;
    int count = TabPane::tabs->count();
    for (int i = 0; i<count; i++) {
        if (TabPane::widgetAt(i)->isModified()) {
            found = true;
            items.push_back(TabPane::widgetAt(i)->path());
        }
    }

    if (found) {
        QString details = "";
        for (int i = 0; i<items.size(); i++) {
            details+=items.at(i)+"\n";
        }

        QMessageBox msg;
        msg.setWindowTitle("Warning!");
        msg.setText("You have unsaved documents!\n"
                    "Do you wish to exit?");
        msg.setDetailedText(details);
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg.setDefaultButton(QMessageBox::No);
        msg.setIcon(QMessageBox::Warning);
        int ret = msg.exec();

        if (ret==QMessageBox::Yes) {
            return true;
        }
        return false;
    }
    return true;
}

void Window::displayProjectPane() {
    if (projectPane->isVisible()) {
        projectPane->hide();
    } else {
        projectPane->loadTree();
        projectPane->show();
    }
}

void Window::dispalyDateSelector() {
    if (dateDockWidget->isHidden()) {
        dateDockWidget->show();
    } else {
        dateDockWidget->hide();
    }
}

void Window::appExit(QMainWindow *win, bool quit) {
    settings.setValue("subwindows/date_selector",QVariant(dateDockWidget->isHidden()).toString());
    Recent::write();
    if (quit) {
    	qApp->exit(0);
    }
}

void Window::closeEvent(QCloseEvent *event) {
    if (checkSave()) {
    	appExit(this,false);
        event->accept();
    } else {
        event->ignore();
    }
}

void Window::onWindowStateChanged(Qt::ApplicationState state) {
    switch (state) {
    case Qt::ApplicationSuspended: {
    } break;
    case Qt::ApplicationHidden: {
    } break;
    case Qt::ApplicationInactive: {
    } break;
    case Qt::ApplicationActive: {
        if (TabPane::currentWidget()->isUntitled()) {
            return;
        }
        QString path = TabPane::currentWidget()->path();
        QString currentContent = FileActions::fileContents(path);
        QString oldContent = TabPane::currentWidget()->saveContent();
        if (currentContent.trimmed()!=oldContent.trimmed()) {
            TabPane::currentEditor()->setReadOnly(true);
            QMessageBox msg;
            msg.setWindowTitle("File Changed");
            msg.setText("This file has been changed outside of the editor.\n"
                        "Do you wish to reload it?");
            msg.setIcon(QMessageBox::Question);
            msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            int ret = msg.exec();
            TabPane::currentEditor()->setReadOnly(false);
            if (ret==QMessageBox::Yes) {
                QString content = FileActions::fileContents(path);
                TabPane::setCurrentTabText(content);
                TabPane::currentWidget()->setModified(false);
            } else {
                return;
            }
        }
    } break;
    }
}

