//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "editor_context.hpp"

EditorContextMenu::EditorContextMenu() {
    cut = new CutAction(this);
    copy = new CopyAction(this);
    paste = new PasteAction(this);
    selectAll = new SelectAllAction(this);
    redo = new RedoAction(this);
    undo = new UndoAction(this);

    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
    this->addSeparator();
    this->addAction(selectAll);
    this->addAction(redo);
    this->addAction(undo);
}

EditorContextMenu::~EditorContextMenu() {
    delete cut;
    delete copy;
    delete paste;
    delete selectAll;
    delete redo;
    delete undo;
}
