//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMainWindow>
#include <QCloseEvent>

#include "menubar/filemenu.hpp"
#include "menubar/format_menu.hpp"
#include "menubar/cellmenu.hpp"
#include "menubar/helpmenu.hpp"
#include "statusbar.hpp"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    ~Window();
    static void setCurrentPath(QString path);
    static void setCurrentSaved(bool saved);
    static bool checkSave();
protected:
    void closeEvent(QCloseEvent *event);
private:
    FileMenu *filemenu;
    FormatMenu *formatMenu;
    CellMenu *cellMenu;
    HelpMenu *helpMenu;
    static StatusBar *statusbar;
};
