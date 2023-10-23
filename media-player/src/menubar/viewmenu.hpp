//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class ViewMenu : public QMenu {
    Q_OBJECT
public:
    ViewMenu();
    ~ViewMenu();
private:
    QAction *fullScreen, *playlist;
private slots:
    void onFullScreenClicked();
    void onPlaylistClicked();
};
