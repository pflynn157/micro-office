//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QButtonGroup>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

#include "browserwidget.hpp"
#include "endtoolbar.hpp"

class AddrPushButton;
class AddrButtonMenu;

class AddressBarButtons : public QToolBar {
    Q_OBJECT
public:
    AddressBarButtons();
    ~AddressBarButtons();
    void setBrowserWidget(BrowserWidget *b);
    void parsePath(QString path);
private:
    BrowserWidget *bWidget;
    QToolBar *subBar;
    QButtonGroup *group;
    QWidget *spacer;
    EndToolbar *endtoolbar;
    void parseClean(QString path);
private slots:
    void onDirChanged(QString path);
};

class AddrPushButton : public QPushButton {
    Q_OBJECT
public:
    explicit AddrPushButton(QString path, BrowserWidget *b);
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QString fullpath;
    BrowserWidget *bWidget;
private slots:
    void onClicked();
};

class AddrButtonMenu : public QMenu {
    Q_OBJECT
public:
    explicit AddrButtonMenu(BrowserWidget *b, QString fullpath);
    ~AddrButtonMenu();
private:
    BrowserWidget *bWidget;
    QString path;
    QAction *open, *openTab;
private slots:
    void onOpenClicked();
    void onOpenTabClicked();
};
