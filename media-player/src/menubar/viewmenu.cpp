//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QMenu>
#include <QAction>
#include <QPixmap>

#include "viewmenu.hpp"
#include "../actions.hpp"
#include "../window.hpp"

ViewMenu::ViewMenu() {
    this->setTitle("View");

    fullScreen = new QAction("Fullscreen",this);
    playlist = new QAction("Show Playlist",this);

    QPixmap fullScreenIcon(":/icons/view-fullscreen.svg");
#ifdef NO_THEME_ICONS
    fullScreen->setIcon(fullScreenIcon);
#else
    fullScreen->setIcon(QIcon::fromTheme("view-fullscreen",fullScreenIcon));
#endif

    connect(fullScreen,SIGNAL(triggered(bool)),this,SLOT(onFullScreenClicked()));
    connect(playlist,&QAction::triggered,this,&ViewMenu::onPlaylistClicked);

    this->addAction(fullScreen);
    this->addAction(playlist);
}

ViewMenu::~ViewMenu() {
    delete fullScreen;
}

void ViewMenu::onFullScreenClicked() {
	Actions::setWindowFullscreen();
}

void ViewMenu::onPlaylistClicked() {
    Window::dspPlaylist();
}
