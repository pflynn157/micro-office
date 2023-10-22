//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>

#include "file_contextmenu.hpp"
#include "../clipboard.hpp"
#include "../actions.hpp"
#include "../tabwidget.hpp"
#include "../trash.hpp"
#include "../dialogs/appchooserdialog.hpp"

FileContextMenu::FileContextMenu(BrowserWidget *b) {
    bWidget = b;

    open = new QAction(QIcon::fromTheme("document-open"),"Open",this);
    openWith = new QAction("Open With",this);
    cut = new QAction(QIcon::fromTheme("edit-cut"),"Cut",this);
    copy = new QAction(QIcon::fromTheme("edit-copy"),"Copy",this);
    rename = new QAction(QIcon::fromTheme("edit-rename"),"Rename",this);
    trash = new QAction(QIcon::fromTheme("user-trash"),"Move to Trash",this);
    restore = new QAction(QIcon::fromTheme("view-refresh"),"Restore",this);
    deleteFile = new QAction(QIcon::fromTheme("edit-delete"),"Delete",this);

    connect(open,&QAction::triggered,this,&FileContextMenu::onOpenClicked);
    connect(openWith,&QAction::triggered,this,&FileContextMenu::onOpenWithClicked);
    connect(cut,&QAction::triggered,this,&FileContextMenu::onCutClicked);
    connect(copy,&QAction::triggered,this,&FileContextMenu::onCopyClicked);
    connect(rename,&QAction::triggered,this,&FileContextMenu::onRenameClicked);
    connect(trash,&QAction::triggered,this,&FileContextMenu::onTrashClicked);
    connect(restore,&QAction::triggered,this,&FileContextMenu::onRestoreClicked);
    connect(deleteFile,&QAction::triggered,this,&FileContextMenu::onDeleteClicked);

    this->addAction(open);
    this->addAction(openWith);
    this->addSeparator();
    this->addAction(cut);
    this->addAction(copy);
    this->addSeparator();
    this->addAction(rename);
    this->addSeparator();
    if (TabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
        this->addAction(restore);
    } else {
        this->addAction(trash);
    }
    this->addAction(deleteFile);
}

FileContextMenu::~FileContextMenu() {
    delete open;
    delete openWith;
    delete cut;
    delete copy;
    delete rename;
    delete trash;
    delete restore;
    delete deleteFile;
}

void FileContextMenu::onOpenClicked() {
    Actions::openCurrentFile();
}

void FileContextMenu::onOpenWithClicked() {
    AppChooserDialog dialog(bWidget->currentItemName());
    dialog.exec();
}

void FileContextMenu::onCutClicked() {
    clipboard.fileName = bWidget->currentItemNames();
    clipboard.oldPath = bWidget->fsCurrentPath();
    clipboard.action = Clipboard_Actions::CUT;
}

void FileContextMenu::onCopyClicked() {
    clipboard.fileName = bWidget->currentItemNames();
    clipboard.oldPath = bWidget->fsCurrentPath();
    clipboard.action = Clipboard_Actions::COPY;
}

void FileContextMenu::onRenameClicked() {
    Actions::rename();
}

void FileContextMenu::onTrashClicked() {
    Actions::trash();
}

void FileContextMenu::onRestoreClicked() {
    Actions::restore();
}

void FileContextMenu::onDeleteClicked() {
    if (TabWidget::currentWidget()->fsCurrentPath()==Trash::folderPath) {
        Trash::deleteCurrentFile();
    } else {
        Actions::deleteFolder();
    }
}
