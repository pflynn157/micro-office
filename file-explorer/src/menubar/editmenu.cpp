//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QKeySequence>

#include "editmenu.hpp"
#include "../clipboard.hpp"
#include "../tabwidget.hpp"
#include "../actions.hpp"

EditMenu::EditMenu() {
    this->setTitle("Edit");

    selectAll = new QAction(QIcon::fromTheme("edit-select-all",QPixmap(":/icons/edit-select-all.svg")),"Select All",this);
    cut = new QAction(QIcon::fromTheme("edit-cut",QPixmap(":/icons/edit-cut.svg")),"Cut",this);
    copy = new QAction(QIcon::fromTheme("edit-copy",QPixmap(":/icons/edit-copy.svg")),"Copy",this);
    paste = new QAction(QIcon::fromTheme("edit-paste",QPixmap(":/icons/edit-paste.svg")),"Paste",this);
    trash = new QAction(QIcon::fromTheme("user-trash",QPixmap(":/icons/user-trash.svg")),"Trash",this);
    deleteFile = new QAction(QIcon::fromTheme("edit-delete",QPixmap(":/icons/edit-delete.svg")),"Delete",this);

    selectAll->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    cut->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
    copy->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    paste->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_V));
    trash->setShortcut(QKeySequence(Qt::Key_Delete));
    deleteFile->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_D));

    connect(selectAll,&QAction::triggered,this,&EditMenu::onSelectAllClicked);
    connect(cut,&QAction::triggered,this,&EditMenu::onCutClicked);
    connect(copy,&QAction::triggered,this,&EditMenu::onCopyClicked);
    connect(paste,&QAction::triggered,this,&EditMenu::onPasteClicked);
    connect(trash,&QAction::triggered,this,&EditMenu::onTrashClicked);
    connect(deleteFile,&QAction::triggered,this,&EditMenu::onDeleteFileClicked);

    this->addAction(selectAll);
    this->addSeparator();
    this->addAction(cut);
    this->addAction(copy);
    this->addAction(paste);
    this->addSeparator();
    this->addAction(trash);
    this->addAction(deleteFile);
}

EditMenu::~EditMenu() {
    delete selectAll;
    delete cut;
    delete copy;
    delete paste;
    delete trash;
    delete deleteFile;
}

void EditMenu::onSelectAllClicked() {
    TabWidget::currentWidget()->selectAll();
}

void EditMenu::onCutClicked() {
    clipboard.fileName = TabWidget::currentWidget()->currentItemNames();
    clipboard.oldPath = TabWidget::currentWidget()->fsCurrentPath();
    clipboard.action = Clipboard_Actions::CUT;
}

void EditMenu::onCopyClicked() {
    clipboard.fileName = TabWidget::currentWidget()->currentItemNames();
    clipboard.oldPath = TabWidget::currentWidget()->fsCurrentPath();
    clipboard.action = Clipboard_Actions::COPY;
}

void EditMenu::onPasteClicked() {
    clipboard.newPath = TabWidget::currentWidget()->fsCurrentPath();
    Actions::paste();
}

void EditMenu::onTrashClicked() {
    Actions::trash();
}

void EditMenu::onDeleteFileClicked() {
    Actions::deleteFile();
}
