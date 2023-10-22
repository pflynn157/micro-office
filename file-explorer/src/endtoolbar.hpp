//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>

#include "browserwidget.hpp"

class EndToolbar : public QToolBar {
    Q_OBJECT
public:
    EndToolbar();
    ~EndToolbar();
    void setBrowserWidget(BrowserWidget *b);
private:
    BrowserWidget *bWidget;
    QToolButton *showTxtAddr, *iconView, *listView;
private slots:
    void onShowTxtAddr();
    void onIconViewClicked();
    void onListViewClicked();
};
