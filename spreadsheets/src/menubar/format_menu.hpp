//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class FormatMenu : public QMenu {
    Q_OBJECT
public:
    FormatMenu();
    ~FormatMenu();
private:
    QAction *bold, *italic, *underline;
    QMenu *colorMenu;
    QAction *bg, *fg, *border;
    QAction *setFont;
private slots:
    void onBoldClicked();
    void onItalicClicked();
    void onUnderlineClicked();
    void onBgColorClicked();
    void onFgColorClicked();
    void onBorderClicked();
    void onSetFontClicked();
};
