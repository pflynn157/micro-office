//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>

#include "tray.hpp"
#include "global.hpp"
#include "videopane.hpp"
#include "actions.hpp"

SysTray::SysTray() {
    QPixmap trayIcon(":/icons/cpp-media-player.svg");
    this->setIcon(QIcon::fromTheme("applications-multimedia",trayIcon));

    contextMenu = new QMenu;
    this->setContextMenu(contextMenu);

    play = new QAction("Play",contextMenu);
    pause = new QAction("Pause",contextMenu);
    stop = new QAction("Stop",contextMenu);
    open = new QAction("Open",contextMenu);
    back = new QAction("Back",contextMenu);
    forward = new QAction("Forward",contextMenu);
    hideWindow = new QAction("Hide Window",contextMenu);
    quit = new QAction("Quit",contextMenu);

    QPixmap documentOpenIcon(":/icons/document-open.svg");
    QPixmap playIcon(":/icons/media-playback-start.svg");
    QPixmap pauseIcon(":/icons/media-playback-pause.svg");
    QPixmap stopIcon(":/icons/media-playback-stop.svg");
    QPixmap backIcon(":/icons/media-seek-backward.svg");
    QPixmap forwardIcon(":/icons/media-seek-forward.svg");
    QPixmap quitIcon(":/icons/window-close.svg");

    play->setIcon(QIcon::fromTheme("media-playback-start",playIcon));
    pause->setIcon(QIcon::fromTheme("media-playback-pause",pauseIcon));
    stop->setIcon(QIcon::fromTheme("media-playback-stop",stopIcon));
    open->setIcon(QIcon::fromTheme("document-open",documentOpenIcon));
    back->setIcon(QIcon::fromTheme("media-seek-backward",backIcon));
    forward->setIcon(QIcon::fromTheme("media-seek-forward",forwardIcon));
    quit->setIcon(QIcon::fromTheme("window-close",quitIcon));

    hideWindow->setCheckable(true);

    connect(play,&QAction::triggered,this,&SysTray::onPlayClicked);
    connect(pause,&QAction::triggered,this,&SysTray::onPauseClicked);
    connect(stop,&QAction::triggered,this,&SysTray::onStopClicked);
    connect(open,&QAction::triggered,this,&SysTray::onOpenClicked);
    connect(back,&QAction::triggered,this,&SysTray::onBackClicked);
    connect(forward,&QAction::triggered,this,&SysTray::onForwardClicked);
    connect(hideWindow,&QAction::triggered,this,&SysTray::onHideWindowClicked);
    connect(quit,&QAction::triggered,qApp,&QApplication::quit);

    contextMenu->addAction(play);
    contextMenu->addAction(pause);
    contextMenu->addAction(stop);
    contextMenu->addAction(back);
    contextMenu->addAction(forward);
    contextMenu->addAction(open);
    contextMenu->addAction(hideWindow);
    contextMenu->addAction(quit);
}

SysTray::~SysTray() {
    delete contextMenu;
}

void SysTray::onPlayClicked() {
    VideoPane::player->play();
}

void SysTray::onPauseClicked() {
    VideoPane::player->pause();
}

void SysTray::onStopClicked() {
    VideoPane::player->stop();
}

void SysTray::onOpenClicked() {
    bool was = false;
    if (globalVars.window->isHidden()) {
        globalVars.window->show();
        was = true;
    }
    Actions::open();
    if (was) {
        globalVars.window->hide();
    }
}

void SysTray::onBackClicked() {
    Actions::seekBack();
}

void SysTray::onForwardClicked() {
    Actions::seekForward();
}

void SysTray::onHideWindowClicked() {
    if (hideWindow->isChecked()) {
        isWindowMaximized = globalVars.window->isMaximized();
        globalVars.window->hide();
    } else {
        if (isWindowMaximized) {
            globalVars.window->showMaximized();
        } else {
            globalVars.window->show();
        }
    }
}
