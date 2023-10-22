//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QPixmap>
#include <QApplication>
#include <QMessageBox>

#include "helpmenu.hpp"

HelpMenu::HelpMenu() {
    this->setTitle("Help");

    about = new QAction("About",this);
    aboutQt = new QAction("About Qt",this);

    about->setIcon(QPixmap(":/icons/help-about.svg"));

    connect(about,&QAction::triggered,this,&HelpMenu::onAboutClicked);
    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);

    this->addAction(about);
    this->addAction(aboutQt);
}

HelpMenu::~HelpMenu() {
    delete about;
    delete aboutQt;
}

void HelpMenu::onAboutClicked() {
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("About CppSheets");
    msg.setText("CppSheets: A simple spreadsheet application.\n"
                "Written by Patrick; see <https://github.com/patrickf2000/CppSheets>\n\n"
                "Credits:\n"
                "xlnt <https://github.com/tfussell/xlnt>\n"
                "tinyxml2 <https://github.com/leethomason/tinyxml2>");
    msg.exec();
}
