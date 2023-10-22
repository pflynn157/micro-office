//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>

#include "browserwidget.hpp"

class NavBar : public QToolBar {
    Q_OBJECT
public:
    NavBar();
    ~NavBar();
    void setBrowserWidget(BrowserWidget *b);
private:
    BrowserWidget *bWidget;
    QToolButton *goBack, *goUp, *refresh, *home;
private slots:
    void onGoUpClicked();
    void onGoBackClicked();
    void onRefreshClicked();
    void onHomeClicked();
    void onDirChanged(QString path);
    void onHistoryChanged();
};
