//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QContextMenuEvent>

#include "navbar.hpp"
#include "addressbar_text.hpp"
#include "addressbar_buttons.hpp"
#include "tabwidget.hpp"
#include "sidebar.hpp"

#include "menubar/filemenu.hpp"
#include "menubar/editmenu.hpp"
#include "menubar/viewmenu.hpp"
#include "menubar/helpmenu.hpp"

class FileMenu;
class MenuBar;

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window(QWidget *parent = 0);
    ~Window();
    void closeApp();
    static AddressBarText *addrTxt;
    static AddressBarButtons *addrButtons;
protected:
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    NavBar *navbar;
    FileMenu *filemenu;
    EditMenu *editmenu;
    ViewMenu *viewmenu;
    HelpMenu *helpmenu;
    TabWidget *tabPane;
    SideBar *sidebar;
};
