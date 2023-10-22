//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QString>
#include <QFileDialog>
#include <QStringList>

#include "actions.hpp"
#include "videopane.hpp"
#include "menubar/recent.hpp"
#include "menubar/filemenu.hpp"
#include "global.hpp"

bool Actions::maximized;

void Actions::open() {
    QFileDialog dialog;
    dialog.setWindowTitle("Open Media File");
    if (dialog.exec()) {
        QStringList contents = dialog.selectedFiles();
        if (contents.size()<1) {
            return;
        }
        QString selected = contents.at(0);
        Recent recent;
        recent.addRecent(selected);
        recent.write();
        FileMenu::refreshRecentEntries();
        VideoPane::addMedia(selected);
        VideoPane::startPlaying();
    }
}

void Actions::setWindowFullscreen() {
    if (globalVars.window->isFullScreen()) {
        if (maximized) {
            globalVars.window->showMaximized();
        } else {
            globalVars.window->showNormal();
        }
    } else {
        maximized = globalVars.window->isMaximized();
        globalVars.window->showFullScreen();
    }
}

void Actions::seekBack() {
    //int index = VideoPane::player->playlist()->currentIndex();
    //VideoPane::player->playlist()->setCurrentIndex(index-1);
}

void Actions::seekForward() {
    //int index = VideoPane::player->playlist()->currentIndex();
    //VideoPane::player->playlist()->setCurrentIndex(index+1);
}
