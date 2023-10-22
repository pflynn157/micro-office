//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include "../browserwidget.hpp"

class FileContextMenu : public QMenu {
    Q_OBJECT
public:
    explicit FileContextMenu(BrowserWidget *b);
    ~FileContextMenu();
private:
    BrowserWidget *bWidget;
    QAction *open, *openWith, *cut, *copy, *rename, *trash, *restore, *deleteFile;
private slots:
    void onOpenClicked();
    void onOpenWithClicked();
    void onCutClicked();
    void onCopyClicked();
    void onRenameClicked();
    void onTrashClicked();
    void onRestoreClicked();
    void onDeleteClicked();
};
