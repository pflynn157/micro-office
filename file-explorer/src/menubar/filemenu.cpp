//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QApplication>
#include <QKeySequence>

#include "filemenu.hpp"
#include "../actions.hpp"
#include "../tabwidget.hpp"

FileMenu::FileMenu(Window *p) {
    parent = p;

    this->setTitle("File");

    newTab = new QAction(QIcon::fromTheme("tab-new",QPixmap(":/icons/tab-new.svg")),"New Tab",this);
    closeTab = new QAction(QIcon::fromTheme("tab-close",QPixmap(":/icons/window-close.svg")),"Close Tab",this);
    newFile = new QAction(QIcon::fromTheme("document-new",QPixmap(":/icons/document-new.svg")),"New File",this);
    newFolder = new QAction(QIcon::fromTheme("folder-new",QPixmap(":/icons/folder-new.svg")),"New Folder",this);
    quit = new QAction(QIcon::fromTheme("application-exit",QPixmap(":/icons/application-exit.svg")),"Exit",this);

    newTab->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_T));
    closeTab->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_T));
    newFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    newFolder->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    quit->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));

    connect(newTab,&QAction::triggered,this,&FileMenu::onNewTabClicked);
    connect(closeTab,&QAction::triggered,this,&FileMenu::onCloseTabClicked);
    connect(newFile,&QAction::triggered,this,&FileMenu::onNewFileClicked);
    connect(newFolder,&QAction::triggered,this,&FileMenu::onNewFolderClicked);
    connect(quit,&QAction::triggered,this,&FileMenu::onQuitClicked);

    this->addAction(newTab);
    this->addAction(closeTab);
    this->addSeparator();
    this->addAction(newFile);
    this->addAction(newFolder);
    this->addSeparator();
    this->addAction(quit);
}

FileMenu::~FileMenu() {
    delete newTab;
    delete closeTab;
    delete newFile;
    delete newFolder;
    delete quit;
}

void FileMenu::onNewTabClicked() {
    TabWidget::addNewTab();
}

void FileMenu::onCloseTabClicked() {
    TabWidget::closeCurrentTab();
}

void FileMenu::onNewFileClicked() {
    Actions::newFile();
}

void FileMenu::onNewFolderClicked() {
    Actions::newFolder();
}

void FileMenu::onQuitClicked() {
    parent->closeApp();
    qApp->exit(0);
}
