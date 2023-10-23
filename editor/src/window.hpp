//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
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

