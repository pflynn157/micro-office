//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include <actions.hpp>

class EditMenu : public QMenu {
    Q_OBJECT
public:
    EditMenu();
    ~EditMenu();
private:
    CutAction *cut;
    CopyAction *copy;
    PasteAction *paste;
    SelectAllAction *selectAll;
    UndoAction *undo;
    RedoAction *redo;
    QAction *find;
    QAction *settings;
private:
    void onFindClicked();
    void onSettingsClicked();
};

