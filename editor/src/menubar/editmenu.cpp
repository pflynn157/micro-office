//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <window.hpp>
#include <icon.hpp>
#include <tabpane.hpp>
#include <menubar/editmenu.hpp>
#include <settings/settings_dialog.hpp>

EditMenu::EditMenu() {
    this->setTitle("Edit");

    cut = new CutAction(this);
    copy = new CopyAction(this);
    paste = new PasteAction(this);
    selectAll = new SelectAllAction(this);
    undo = new UndoAction(this);
    redo = new RedoAction(this);
    find = new QAction(IconManager::getIcon("edit-find"),"Find/Replace Text",this);
    settings = new QAction("Settings", this);

    connect(find, &QAction::triggered, this, &EditMenu::onFindClicked);
    connect(settings, &QAction::triggered, this, &EditMenu::onSettingsClicked);

    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
    this->addAction(selectAll);
    this->addSeparator();
    this->addAction(undo);
    this->addAction(redo);
    this->addSeparator();
    this->addAction(find);
    this->addSeparator();
    this->addAction(settings);
}

EditMenu::~EditMenu() {
    delete cut;
    delete copy;
    delete paste;
    delete selectAll;
    delete undo;
    delete redo;
    delete find;
    delete settings;
}

void EditMenu::onFindClicked() {
    TabPane::currentWidget()->displayFinder();
}

void EditMenu::onSettingsClicked() {
    SettingsDialog dialog;
    dialog.exec();
}

