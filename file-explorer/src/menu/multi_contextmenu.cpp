//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "multi_contextmenu.hpp"
#include "../clipboard.hpp"
#include "../actions.hpp"
#include "../trash.hpp"
#include "../tabwidget.hpp"

MultiContextMenu::MultiContextMenu(BrowserWidget *b) {
    bWidget = b;

    cut = new QAction(QIcon::fromTheme("edit-cut"),"Cut",this);
    copy = new QAction(QIcon::fromTheme("edit-copy"),"Copy",this);
    trash = new QAction(QIcon::fromTheme("user-trash"),"Move to Trash",this);
    restore = new QAction(QIcon::fromTheme("view-refresh"),"Restore",this);
    deleteAll = new QAction(QIcon::fromTheme("edit-delete"),"Delete",this);

    connect(cut,&QAction::triggered,this,&MultiContextMenu::onCutClicked);
    connect(copy,&QAction::triggered,this,&MultiContextMenu::onCopyClicked);
    connect(trash,&QAction::triggered,this,&MultiContextMenu::onTrashClicked);
    connect(restore,&QAction::triggered,this,&MultiContextMenu::onRestoreClicked);
    connect(deleteAll,&QAction::triggered,this,&MultiContextMenu::onDeleteAllClicked);

    this->addAction(cut);
    this->addAction(copy);
    this->addSeparator();
    if (TabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
        this->addAction(restore);
    } else {
        this->addAction(trash);
    }
    this->addAction(deleteAll);
}

MultiContextMenu::~MultiContextMenu() {
    delete cut;
    delete copy;
    delete trash;
    delete restore;
    delete deleteAll;
}

void MultiContextMenu::onCutClicked() {
    clipboard.fileName = bWidget->currentItemNames();
    clipboard.oldPath = bWidget->fsCurrentPath();
    clipboard.action = Clipboard_Actions::CUT;
}

void MultiContextMenu::onCopyClicked() {
    clipboard.fileName = bWidget->currentItemNames();
    clipboard.oldPath = bWidget->fsCurrentPath();
    clipboard.action = Clipboard_Actions::COPY;
}

void MultiContextMenu::onTrashClicked() {
    Actions::trash();
}

void MultiContextMenu::onRestoreClicked() {
    Actions::restore();
}

void MultiContextMenu::onDeleteAllClicked() {
    Actions::deleteFile();
}
