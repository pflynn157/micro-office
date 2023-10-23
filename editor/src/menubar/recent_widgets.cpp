//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QStringList>
#include <QFile>
#include <QString>

#include "recent_widgets.hpp"
#include "../window.hpp"
#include "../global/recent.hpp"

RecentAction::RecentAction(QString title, QMenu *parent) : QAction(title,parent) {
    path = title;
    connect(this,&QAction::triggered,this,&RecentAction::onClicked);
}

void RecentAction::onClicked() {
    Window::addFile(path);
    Recent::addRecentItem(path);
}

RecentMenu::RecentMenu() {
    this->setTitle("Recent");
    loadEntries();
}

RecentMenu::~RecentMenu() {
    delete clearItems;
}

void RecentMenu::loadEntries() {
    this->clear();
    clearItems = new QAction("Clear List",this);
    connect(clearItems,&QAction::triggered,this,&RecentMenu::onClearItemsClicked);
    this->addAction(clearItems);
    this->addSeparator();

    QStringList *items = Recent::allItems();
    if (items->size()==0) {
        QAction *action = new QAction("None",this);
        action->setEnabled(false);
        this->addAction(action);
    } else {
        QStringList *update = new QStringList;
        for (int i = 0; i<items->size(); i++) {
            update->push_front(items->at(i));
        }
        for (int i = 0; i<update->size(); i++) {
            RecentAction *action = new RecentAction(update->at(i),this);
            this->addAction(action);
        }
    }
}

void RecentMenu::onClearItemsClicked() {
    QString path = Recent::recentFilePath();
    QFile file(path);
    if (file.exists()) {
        file.remove();
        Recent::clearAll();
        loadEntries();
    }
}
