//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QKeySequence>

#include <actions.hpp>
#include <icon.hpp>
#include <global/slots.hpp>

Action::Action(QString name, QString iconName, QObject *parent) : QAction(name,parent) {
    this->setIcon(IconManager::getIcon(iconName));
}

CopyAction::CopyAction(QObject *parent) : Action("Copy","edit-copy",parent) {
    this->setShortcut(QKeySequence::Copy);
    connect(this,&QAction::triggered,new Slots,&Slots::copySlot);
}

CutAction::CutAction(QObject *parent) : Action("Cut","edit-cut",parent) {
    this->setShortcut(QKeySequence::Cut);
    connect(this,&QAction::triggered,new Slots,&Slots::cutSlot);
}

PasteAction::PasteAction(QObject *parent) : Action("Paste","edit-paste",parent) {
    this->setShortcut(QKeySequence::Paste);
    connect(this,&QAction::triggered,new Slots,&Slots::pasteSlot);
}

RedoAction::RedoAction(QObject *parent) : Action("Redo","edit-redo",parent) {
    this->setShortcut(QKeySequence::Redo);
    connect(this,&QAction::triggered,new Slots,&Slots::redoSlot);
}

SelectAllAction::SelectAllAction(QObject *parent) : Action("Select All","edit-select-all",parent) {
    this->setShortcut(QKeySequence::SelectAll);
    connect(this,&QAction::triggered,new Slots,&Slots::selectAllSlot);
}

UndoAction::UndoAction(QObject *parent) : Action("Undo","edit-undo",parent) {
    this->setShortcut(QKeySequence::Undo);
    connect(this,&QAction::triggered,new Slots,&Slots::undoSlot);
}

