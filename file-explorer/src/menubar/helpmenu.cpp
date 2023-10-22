//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QApplication>

#include "helpmenu.hpp"
#include "../dialogs/helpdialog.hpp"
#include "../dialogs/keyboardshortcutsdialog.hpp"

HelpMenu::HelpMenu() {
    this->setTitle("Help");

    keyboardShortcuts = new QAction("Keyboard Shortcuts",this);
    aboutQt = new QAction("About Qt",this);
    about = new QAction(QIcon::fromTheme("help-about",QPixmap(":/icons/help-about.svg")),"About",this);

    connect(keyboardShortcuts,&QAction::triggered,this,&HelpMenu::onKeyboardShortcutsClicked);
    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(about,&QAction::triggered,this,&HelpMenu::onAboutClicked);

    this->addAction(keyboardShortcuts);
    this->addSeparator();
    this->addAction(aboutQt);
    this->addAction(about);
}

HelpMenu::~HelpMenu() {
    delete keyboardShortcuts;
    delete aboutQt;
    delete about;
}

void HelpMenu::onKeyboardShortcutsClicked() {
    KeyboardShortcutsDialog().exec();
}

void HelpMenu::onAboutClicked() {
    HelpDialog().exec();
}
