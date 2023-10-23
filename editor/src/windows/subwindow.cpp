//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QCursor>

#include "subwindow.hpp"
#include "../menus/dock_widget_menu.hpp"

void SubWindow::contextMenuEvent(QContextMenuEvent *event) {
    DockWidgetMenu menu(this);
    menu.exec(QCursor::pos());
    menu.show();
}
