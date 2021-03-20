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
#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QSplitter>
#include <QTextEdit>
#include <QStatusBar>
#include <QCheckBox>

#include "windows/date_selector.hpp"
#include "project/project_pane.hpp"
#include <main_toolbar.hpp>

#include "menubar/filemenu.hpp"
#include "menubar/editmenu.hpp"
#include "menubar/insertmenu.hpp"
#include "menubar/viewmenu.hpp"
#include "menubar/helpmenu.hpp"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    ~Window();
    void setTitle(QString title, bool custom = false);
    MainToolBar *getMainToolbar();
    
    static void addFile(QString path);
    static QStatusBar *statusbar;
    static void setStatusBarModified(bool modified);
    static void setStatusBarPath(QString path);
    static void setStatusBarLineCount(int count);
    static bool checkSave();
    static void displayProjectPane();
    static void dispalyDateSelector();
    static void appExit(QMainWindow *win, bool quit);
    
    static QCheckBox *useTabs;
    static QCheckBox *intelIndent;
protected:
	void closeEvent(QCloseEvent *event);
private:
    static QLabel *modLabel, *pathLabel, *lineCountLabel;
    static QSplitter *centralSplitter;
    static ProjectPane *projectPane;
    static DateDockWidget *dateDockWidget;

    FileMenu *filemenu;
    EditMenu *editmenu;
    InsertMenu *insertmenu;
    ViewMenu *viewmenu;
    HelpMenu *helpmenu;
    
    MainToolBar *toolbar;

    bool customTitle = false;
private slots:
    void onWindowStateChanged(Qt::ApplicationState state);
};

