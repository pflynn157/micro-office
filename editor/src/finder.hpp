//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>
#include <QLineEdit>

#include "editor.hpp"

class Editor;

class Finder : public QToolBar {
    Q_OBJECT
public:
    Finder(Editor *edit);
    ~Finder();
    void clear();
    void findText(bool next, bool replaceText);
private:
    Editor *editor;
    QToolButton *find, *findNext, *replace, *close;
    QLineEdit *entry, *replaceEntry;
    QString lastEntry;
    int count = 0;
    int index = -1;
private slots:
    void onFindClicked();
    void onFindNextClicked();
    void onReplaceClicked();
    void onCloseClicked();
};
