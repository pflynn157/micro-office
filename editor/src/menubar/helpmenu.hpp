//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class HelpMenu : public QMenu {
    Q_OBJECT
public:
    HelpMenu();
    ~HelpMenu();
private:
    QAction *aboutQt, *about;
private slots:
    void onAboutClicked();
};
