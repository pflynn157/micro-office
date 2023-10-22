//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include "../browserwidget.hpp"

class BackgroundContextMenu : public QMenu {
    Q_OBJECT
public:
    explicit BackgroundContextMenu(BrowserWidget *b);
    ~BackgroundContextMenu();
private:
    BrowserWidget *bWidget;
    QAction *newFolder, *newFile, *paste;
private slots:
    void onNewFolderClicked();
    void onNewFileClicked();
    void onPasteClicked();
};
