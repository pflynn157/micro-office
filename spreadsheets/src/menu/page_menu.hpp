//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class PageMenu : public QMenu {
    Q_OBJECT
public:
    PageMenu();
    ~PageMenu();
private:
    QAction *copy, *rename;
private slots:
    void onCopyClicked();
    void onRenameClicked();
};
