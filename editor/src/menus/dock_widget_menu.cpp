//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "dock_widget_menu.hpp"

DockWidgetMenu::DockWidgetMenu(QDockWidget *parent) {
    close = new QAction("Close",this);
    this->addAction(close);
    connect(close,&QAction::triggered,parent,&QDockWidget::close);
}

DockWidgetMenu::~DockWidgetMenu() {
    delete close;
}
