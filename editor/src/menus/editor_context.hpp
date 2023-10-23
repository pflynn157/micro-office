//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

#include <actions.hpp>

class EditorContextMenu : public QMenu {
    Q_OBJECT
public:
    EditorContextMenu();
    ~EditorContextMenu();
private:
    CutAction *cut;
    CopyAction *copy;
    PasteAction *paste;
    SelectAllAction *selectAll;
    RedoAction *redo;
    UndoAction *undo;
};
