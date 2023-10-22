//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include "../window.hpp"

class Window;

class FileMenu : public QMenu {
    Q_OBJECT
public:
    FileMenu(Window *p);
    ~FileMenu();
private:
    Window *parent;
    QAction *newTab, *closeTab, *newFile, *newFolder, *quit;
private slots:
    void onNewTabClicked();
    void onCloseTabClicked();
    void onNewFileClicked();
    void onNewFolderClicked();
    void onQuitClicked();
};
