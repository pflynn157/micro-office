//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class RecentAction : public QAction {
    Q_OBJECT
public:
    explicit RecentAction(QString title, QMenu *parent);
private:
    QString path;
private slots:
    void onClicked();
};

class RecentMenu : public QMenu {
    Q_OBJECT
public:
    RecentMenu();
    ~RecentMenu();
    void loadEntries();
private:
    QAction *clearItems;
private slots:
    void onClearItemsClicked();
};
