//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QKeyEvent>

#include "playlist/playlist.hpp"
#include "videopane.hpp"
#include "control.hpp"
#include "tray.hpp"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    void setHeadless(bool headless);
    static void dspPlaylist();
protected:
	void keyPressEvent(QKeyEvent *event);
	void closeEvent(QCloseEvent *event);
private:
    static PlayList *playlist;
    VideoPane *videopane;
    ControlBar *controller;
    SysTray *systray;
    bool isHeadless;
};
