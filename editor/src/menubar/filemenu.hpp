//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>
#include <QMainWindow>

#include "recent_widgets.hpp"

class FileMenu : public QMenu {
    Q_OBJECT
public:
    FileMenu(QMainWindow *window);
    ~FileMenu();
    static RecentMenu *recentMenu;
private:
    QAction *newWin, *newFile, *openFile, *saveFile, *saveFileAs, *quit;
    QMainWindow *win;
private slots:
    void onNewWindowClicked();
    void onQuitClicked();
};
