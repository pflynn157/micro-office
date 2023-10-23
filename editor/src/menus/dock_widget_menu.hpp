//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>
#include <QDockWidget>

class DockWidgetMenu : public QMenu {
    Q_OBJECT
public:
    explicit DockWidgetMenu(QDockWidget *parent);
    ~DockWidgetMenu();
private:
    QAction *close;
};
