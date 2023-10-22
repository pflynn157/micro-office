//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>

#include "sheetwidget.hpp"

class TabWidget : public QWidget {
    Q_OBJECT
public:
    TabWidget();
    ~TabWidget();
    static void addNewTab();
    static void addNewTab(QString file);
    static SheetWidget *currentWidget();
    static SheetWidget *widgetAt(int index);
    static void setCurrentTitle(QString title);
    static QTabWidget *tabs;
private:
    QVBoxLayout *layout;
private slots:
    void onTabCloseRequested(int index);
    void onCurrentChanged();
};
