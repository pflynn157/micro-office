//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QLineEdit>

#include "browserwidget.hpp"
#include "endtoolbar.hpp"

class AddressBarText : public QToolBar {
    Q_OBJECT
public:
    AddressBarText();
    ~AddressBarText();
    void setBrowserWidget(BrowserWidget *b);
private:
    BrowserWidget *bWidget;
    QLineEdit *addressEntry;
    EndToolbar *endtoolbar;
private slots:
    void onAddrEntryReturnPressed();
    void onDirChanged(QString path);
};
