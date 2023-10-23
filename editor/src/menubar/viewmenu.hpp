//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class Window;

class ViewMenu : public QMenu {
    Q_OBJECT
public:
    explicit ViewMenu(Window *parent);
    ~ViewMenu();
private:
    Window *parentWindow;
    bool wasMax = false;
    QAction *projectPane, *setWinTitle, *fullscreen;
private slots:
    void onFullscreenClicked();
    void onSetWinTitleClicked();
    void onProjectPaneClicked();
};
