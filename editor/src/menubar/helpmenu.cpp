//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>
#include <QMessageBox>
#include <iostream>

#include "helpmenu.hpp"
#include "../global/file_actions.hpp"
#include "../icon.hpp"

HelpMenu::HelpMenu() {
    this->setTitle("Help");

    aboutQt = new QAction("About Qt",this);
    about = new QAction("About",this);

    about->setIcon(IconManager::getIcon("help-about"));

    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(about,&QAction::triggered,this,&HelpMenu::onAboutClicked);

    this->addAction(aboutQt);
    this->addAction(about);
}

HelpMenu::~HelpMenu() {
    delete aboutQt;
    delete about;
}

void HelpMenu::onAboutClicked() {
    QMessageBox msg;
    msg.setWindowTitle("About CppEditor");
    msg.setText("CppEditor\n"
                "A simple, cross-platform text editor written in C++ using the Qt libraries.\n");
    msg.setStandardButtons(QMessageBox::Ok);
#ifdef _WIN32
    QString extra = msg.text();
    extra+="\nBuilt for Windows OS";
    msg.setText(extra);
#endif
    msg.exec();
}

