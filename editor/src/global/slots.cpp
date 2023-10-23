//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>

#include "slots.hpp"
#include "file_actions.hpp"
#include "../window.hpp"
#include "../tabpane.hpp"

void Slots::newFileSlot() {
    FileActions::newFile();
}

void Slots::openFileSlot() {
    FileActions::openFile();
}

void Slots::saveFileSlot() {
    FileActions::saveFile();
}

void Slots::saveFileAsSlot() {
    FileActions::saveFileAs();
}

void Slots::quitSlot(QMainWindow *window) {
    if (Window::checkSave()) {
        Window::appExit(window,true);
    }
}

void Slots::cutSlot() {
    TabPane::currentEditor()->cut();
}

void Slots::copySlot() {
    TabPane::currentEditor()->copy();
}

void Slots::pasteSlot() {
    TabPane::currentEditor()->paste();
}

void Slots::selectAllSlot() {
    TabPane::currentEditor()->selectAll();
}

void Slots::undoSlot() {
    TabPane::currentEditor()->undo();
}

void Slots::redoSlot() {
    TabPane::currentEditor()->redo();
}
