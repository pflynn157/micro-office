//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include "../browserwidget.hpp"

class FolderContextMenu : public QMenu {
    Q_OBJECT
public:
    explicit FolderContextMenu(BrowserWidget *b);
    ~FolderContextMenu();
private:
    BrowserWidget *bWidget;
    QAction *openTab, *cut, *copy, *rename, *trash, *restore, *deleteFolder;
private slots:
    void onOpenTabClicked();
    void onCutClicked();
    void onCopyClicked();
    void onRenameClicked();
    void onTrashFolderClicked();
    void onRestoreFolderClicked();
    void onDeleteFolderClicked();
};
