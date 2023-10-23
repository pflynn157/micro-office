//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QInputDialog>

#include "viewmenu.hpp"
#include "../window.hpp"
#include "../icon.hpp"

ViewMenu::ViewMenu(Window *parent) {
    parentWindow = parent;
    this->setTitle("View");

    fullscreen = new QAction("Fullscreen",this);
    setWinTitle = new QAction("Set Window Title", this);
    projectPane = new QAction("Display Project Panel",this);

    projectPane->setCheckable(true);
    projectPane->setChecked(false);

    fullscreen->setIcon(IconManager::getIcon("view-fullscreen"));

    connect(fullscreen, &QAction::triggered, this, &ViewMenu::onFullscreenClicked);
    connect(setWinTitle, &QAction::triggered, this, &ViewMenu::onSetWinTitleClicked);
    connect(projectPane, &QAction::triggered, this, &ViewMenu::onProjectPaneClicked);

    this->addAction(fullscreen);
    this->addAction(setWinTitle);
    this->addAction(projectPane);
}

ViewMenu::~ViewMenu() {
    delete fullscreen;
    delete setWinTitle;
    delete projectPane;
}

void ViewMenu::onFullscreenClicked() {
    if (parentWindow->isFullScreen()) {
        if (wasMax) {
            parentWindow->showMaximized();
        } else {
            parentWindow->showNormal();
        }
    } else {
        if (parentWindow->isMaximized()) {
            wasMax = true;
        } else {
            wasMax = false;
        }
        parentWindow->showFullScreen();
    }
}

void ViewMenu::onSetWinTitleClicked() {
    QString title = QInputDialog::getText(parentWindow, "Change Window Title", "Enter new title:");

    if (title != "") {
        parentWindow->setTitle(title, true);
    }
}

void ViewMenu::onProjectPaneClicked() {
    Window::displayProjectPane();
}

