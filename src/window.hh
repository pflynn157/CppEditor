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
#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QSplitter>
#include <QTextEdit>
#include <QStatusBar>

#include "windows/date_selector.hh"
#include "windows/console/console_win.hh"
#include "project/project_pane.hh"

#include "menubar/filemenu.hh"
#include "menubar/editmenu.hh"
#include "menubar/insertmenu.hh"
#include "menubar/viewmenu.hh"
#include "menubar/template_menu.hh"
#include "menubar/settingsmenu.hh"
#include "menubar/windows_menu.hh"
#include "menubar/helpmenu.hh"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    ~Window();
    void setTitle(QString title);
    static void addFile(QString path);
    static QStatusBar *statusbar;
    static void setStatusBarModified(bool modified);
    static void setStatusBarPath(QString path);
    static void setStatusBarLineCount(int count);
    static bool checkSave();
    static void displayProjectPane();
    static void setRichTextPane(QString text);
    static void displayRichTextPane();
    static bool isRichTextPaneVisible();
    static void dispalyDateSelector();
    static void displayConsole();
    static void displaySysTrayIcon();
    static void appExit(QMainWindow *win, bool quit);
    static TemplateMenu *templateMenu;
protected:
	void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    static QLabel *modLabel, *pathLabel, *lineCountLabel;
    static QSplitter *centralSplitter;
    static ProjectPane *projectPane;
    static QTextEdit *richTextPane;
    static DateDockWidget *dateDockWidget;
    FileMenu *filemenu;
    EditMenu *editmenu;
    InsertMenu *insertmenu;
    ViewMenu *viewmenu;
    SettingsMenu *settingsmenu;
#ifdef _WIN32
    WindowsMenu *windowsMenu;
#endif
    HelpMenu *helpmenu;
#ifndef _WIN32
    static ConsoleWin *consoleWidget;
#endif
    static QSystemTrayIcon *trayIcon;
};
