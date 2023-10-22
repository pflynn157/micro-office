//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QKeySequence>
#include <QPixmap>
#include <QApplication>

#include "filemenu.hpp"
#include "../actions/file_actions.hpp"
#include "../window.hpp"

FileMenu::FileMenu() {
    this->setTitle("File");

    newFile = new QAction("New",this);
    open = new QAction("Open",this);
    save = new QAction("Save",this);
    saveAs = new QAction("Save As",this);
    quit = new QAction("Quit",this);

    newFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    saveAs->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    quit->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));

    newFile->setIcon(QPixmap(":/icons/document-new.svg"));
    open->setIcon(QPixmap(":/icons/document-open.svg"));
    save->setIcon(QPixmap(":/icons/document-save.svg"));
    saveAs->setIcon(QPixmap(":/icons/document-save-as.svg"));
    quit->setIcon(QPixmap(":/icons/application-exit.svg"));

    connect(newFile,&QAction::triggered,this,&FileMenu::onNewFileClicked);
    connect(open,&QAction::triggered,this,&FileMenu::onOpenClicked);
    connect(save,&QAction::triggered,this,&FileMenu::onSaveClicked);
    connect(saveAs,&QAction::triggered,this,&FileMenu::onSaveAsClicked);
    connect(quit,&QAction::triggered,this,&FileMenu::onQuitClicked);

    this->addAction(newFile);
    this->addAction(open);
    this->addAction(save);
    this->addAction(saveAs);
    this->addAction(quit);
}

FileMenu::~FileMenu() {
    delete newFile;
    delete open;
    delete save;
    delete saveAs;
    delete quit;
}

void FileMenu::onNewFileClicked() {
    FileActions::newFile();
}

void FileMenu::onOpenClicked() {
    FileActions::openFile();
}

void FileMenu::onSaveClicked() {
    FileActions::saveFile();
}

void FileMenu::onSaveAsClicked() {
    FileActions::saveFileAs();
}

void FileMenu::onQuitClicked() {
    if (Window::checkSave()) {
        qApp->exit(0);
    }
}
