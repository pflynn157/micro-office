//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QStatusBar>
#include <QLabel>

class StatusBar : public QStatusBar {
    Q_OBJECT
public:
    StatusBar();
    ~StatusBar();
    void setPathLabel(QString label);
    void setSavedLabel(bool saved);
private:
    QLabel *pathLabel;
    QLabel *savedLabel;
};
