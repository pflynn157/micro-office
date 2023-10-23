//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QKeySequence>
#include <QProcess>

#include "filemenu.hpp"
#include "../global/slots.hpp"
#include "../icon.hpp"

RecentMenu *FileMenu::recentMenu;

FileMenu::FileMenu(QMainWindow *window) {
    this->setTitle("File");
    win = window;

    newWin = new QAction("New Window", this);
    newFile = new QAction("New",this);
    openFile = new QAction("Open",this);
    recentMenu = new RecentMenu;
    saveFile = new QAction("Save",this);
    saveFileAs = new QAction("Save As",this);
    quit = new QAction("Quit",this);

    newFile->setIcon(IconManager::getIcon("document-new"));
    openFile->setIcon(IconManager::getIcon("document-open"));
    saveFile->setIcon(IconManager::getIcon("document-save"));
    saveFileAs->setIcon(IconManager::getIcon("document-save-as"));
    quit->setIcon(IconManager::getIcon("application-exit"));

    newFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    openFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    saveFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    saveFileAs->setShortcut(QKeySequence(Qt::SHIFT | Qt::CTRL | Qt::Key_S));
    quit->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));

    connect(newWin, &QAction::triggered, this, &FileMenu::onNewWindowClicked);
    connect(newFile,&QAction::triggered,new Slots,&Slots::newFileSlot);
    connect(openFile,&QAction::triggered,new Slots,&Slots::openFileSlot);
    connect(saveFile,&QAction::triggered,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&QAction::triggered,new Slots,&Slots::saveFileAsSlot);
    connect(quit,&QAction::triggered,this,&FileMenu::onQuitClicked);

    this->addAction(newWin);
    this->addAction(newFile);
    this->addAction(openFile);
    this->addMenu(recentMenu);
    this->addAction(saveFile);
    this->addAction(saveFileAs);
    this->addAction(quit);
}

FileMenu::~FileMenu() {
    delete newWin;
    delete newFile;
    delete openFile;
    delete saveFile;
    delete saveFileAs;
    delete quit;
    delete recentMenu;
}

void FileMenu::onNewWindowClicked() {
    QProcess::startDetached("CppEditor", QStringList() << "--single");
}

void FileMenu::onQuitClicked() {
	Slots *s = new Slots;
	s->quitSlot(win);	
}
