//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QKeySequence>

#include "viewmenu.hpp"
#include "../tabwidget.hpp"

ViewMenu::ViewMenu() {
    this->setTitle("View");

    reload = new QAction(QIcon::fromTheme("view-refresh",QPixmap(":/icons/view-refresh.svg")),"Reload",this);
    hidden = new QAction("View Hidden Files",this);

    hidden->setCheckable(true);
    // hidden->setChecked(QVariant(Settings::getSetting("view/hidden","false")).toBool());

    reload->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    hidden->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));

    connect(reload,&QAction::triggered,this,&ViewMenu::onReloadClicked);
    connect(hidden,&QAction::triggered,this,&ViewMenu::onHiddenClicked);

    this->addAction(reload);
    this->addAction(hidden);
}

ViewMenu::~ViewMenu() {
    delete reload;
    delete hidden;
}

void ViewMenu::onReloadClicked() {
    TabWidget::currentWidget()->reload();
}

void ViewMenu::onHiddenClicked() {
    // Settings::writeSetting("view/hidden",QVariant(hidden->isChecked()).toString());
    TabWidget::currentWidget()->reload();
}
