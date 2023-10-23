//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDockWidget>
#include <QContextMenuEvent>

class SubWindow : public QDockWidget {
    Q_OBJECT
protected:
    void contextMenuEvent(QContextMenuEvent *event);
};
