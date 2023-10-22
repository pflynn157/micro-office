//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include "../browserwidget.hpp"

class MultiContextMenu: public QMenu {
    Q_OBJECT
public:
    explicit MultiContextMenu(BrowserWidget *b);
    ~MultiContextMenu();
private:
    BrowserWidget *bWidget;
    QAction *cut, *copy, *trash, *restore, *deleteAll;
private slots:
    void onCutClicked();
    void onCopyClicked();
    void onTrashClicked();
    void onRestoreClicked();
    void onDeleteAllClicked();
};
