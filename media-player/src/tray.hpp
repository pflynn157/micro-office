//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

class SysTray : public QSystemTrayIcon {
    Q_OBJECT
public:
    SysTray();
    ~SysTray();
private:
    QMenu *contextMenu;
    QAction *play, *pause, *stop, *open;
    QAction *back, *forward, *hideWindow, *quit;
    bool isWindowMaximized;
private slots:
    void onPlayClicked();
    void onPauseClicked();
    void onStopClicked();
    void onOpenClicked();
    void onBackClicked();
    void onForwardClicked();
    void onHideWindowClicked();
};
