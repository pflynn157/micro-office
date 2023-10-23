//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QPixmap>
#include <QFont>
#include <QStringList>

#include "main_toolbar.hpp"
#include "global/slots.hpp"
#include "tabpane.hpp"
#include "global.hpp"
#include "icon.hpp"

MainToolBar::MainToolBar(QMainWindow *parentWindow)
    : newFile(new QToolButton),
      openFile(new QToolButton),
      saveFile(new QToolButton),
      saveFileAs(new QToolButton),
      cut(new QToolButton),
      copy(new QToolButton),
      paste(new QToolButton),
      undo(new QToolButton),
      redo(new QToolButton)
{
    parent = parentWindow;
    this->setContextMenuPolicy(Qt::PreventContextMenu);
    this->setMovable(false);

    syntaxmenu = new QComboBox;
    fontSize = new QSpinBox;
    
    QStringList syntaxItems = repository->getSyntaxList();
    syntaxItems.sort(Qt::CaseInsensitive);
    syntaxItems.push_front("Plain Text");
    syntaxmenu->addItems(syntaxItems);
    
    int size = settings.value("editor/font_size", 12).toInt();

    fontSize->setMinimum(1);
    fontSize->setMaximum(100);
    fontSize->setValue(size);

    newFile->setIcon(IconManager::getIcon("document-new"));
    openFile->setIcon(IconManager::getIcon("document-open"));
    saveFile->setIcon(IconManager::getIcon("document-save"));
    saveFileAs->setIcon(IconManager::getIcon("document-save-as"));
    cut->setIcon(IconManager::getIcon("edit-cut"));
    copy->setIcon(IconManager::getIcon("edit-copy"));
    paste->setIcon(IconManager::getIcon("edit-copy"));
    undo->setIcon(IconManager::getIcon("edit-undo"));
    redo->setIcon(IconManager::getIcon("edit-redo"));

    newFile->setToolTip("New file");
    openFile->setToolTip("Open a file");
    saveFile->setToolTip("Save current file");
    saveFileAs->setToolTip("Save current file as");
    cut->setToolTip("Cut text");
    copy->setToolTip("Copy text");
    paste->setToolTip("Paste text");
    undo->setToolTip("Undo last edit");
    redo->setToolTip("Redo last edit");
    fontSize->setToolTip("Change font size");

    connect(newFile,&QToolButton::clicked,new Slots,&Slots::newFileSlot);
    connect(openFile,&QToolButton::clicked,new Slots,&Slots::openFileSlot);
    connect(saveFile,&QToolButton::clicked,new Slots,&Slots::saveFileSlot);
    connect(saveFileAs,&QToolButton::clicked,new Slots,&Slots::saveFileAsSlot);
    connect(cut,&QToolButton::clicked,new Slots,&Slots::cutSlot);
    connect(copy,&QToolButton::clicked,new Slots,&Slots::copySlot);
    connect(paste,&QToolButton::clicked,new Slots,&Slots::pasteSlot);
    connect(undo,&QToolButton::clicked,new Slots,&Slots::undoSlot);
    connect(redo,&QToolButton::clicked,new Slots,&Slots::redoSlot);
    connect(syntaxmenu,SIGNAL(currentTextChanged(QString)),this,SLOT(onComboTextChanged(QString)));
    connect(fontSize,SIGNAL(valueChanged(int)),this,SLOT(onFontSizeChanged()));

    this->addWidget(newFile);
    this->addWidget(openFile);
    this->addWidget(saveFile);
    this->addWidget(saveFileAs);
    this->addSeparator();
    this->addWidget(cut);
    this->addWidget(copy);
    this->addWidget(paste);
    this->addWidget(undo);
    this->addWidget(redo);
    this->addSeparator();
    this->addWidget(syntaxmenu);
    this->addWidget(fontSize);
}

MainToolBar::~MainToolBar() {
    delete newFile;
    delete openFile;
    delete saveFile;
    delete saveFileAs;
    delete cut;
    delete copy;
    delete paste;
    delete syntaxmenu;
    delete fontSize;
}

void MainToolBar::setFontSize(int val) {
    fontSize->setValue(val);
}

void MainToolBar::setSyntaxName(QString name) {
    syntaxmenu->setCurrentText(name);
}

void MainToolBar::onFontSizeChanged() {
    QFont font = TabPane::currentWidget()->font();
    font.setPointSize(fontSize->value());
    TabPane::currentWidget()->setFont(font);
}

void MainToolBar::onComboTextChanged(QString item) {
    TabPane::currentWidget()->syntaxHighlight(item);
}

