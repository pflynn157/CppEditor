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
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTabWidget>

#include "cpp_message_widget.hpp"
#include "editor.hpp"
#include "window.hpp"

class TabPane : public QFrame {
    Q_OBJECT
public:
    TabPane(Window *parent);
    ~TabPane();
    static QTabWidget *tabs;
    static CppMessageWidget *rootStatus, *settingsSaved, *buttonHidden;

    static void addNewTab(QString path);
    static void addNewUntitledTab();

    static Editor *currentWidget();
    static TextEdit *currentEditor();
    static Editor *widgetAt(int index);
    static TextEdit *editorAt(int index);

    static void setCurrentTabPath(QString path);
    static void setCurrentTabText(QString text);
    static QString currentTabText();

    static void setCurrentTabTitle(QString title);
private:
    static Window *window;
    QVBoxLayout *layout;
private slots:
    void onTabClosed(int index);
    void onTabChanged();
};
