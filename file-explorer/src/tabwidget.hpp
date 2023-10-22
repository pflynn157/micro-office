//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QVector>

#include "browserwidget.hpp"
#include "navbar.hpp"

class TabWidget : public QWidget {
    Q_OBJECT
public:
    explicit TabWidget(NavBar *navbar);
    ~TabWidget();
    static QTabWidget *tabs;
    static void addNewTab(QString path);
    static void addNewTab();
    static void closeCurrentTab();
    static BrowserWidget *currentWidget();
    static void updateTabName();
    static QVector<BrowserWidget *> allWidgets();
private:
    static NavBar *navigationBar;
    QVBoxLayout *layout;
private slots:
    void onTabsChanged();
    void onTabClosed(int index);
};
