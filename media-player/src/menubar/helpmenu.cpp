//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QApplication>
#include <QPixmap>

#include "helpmenu.hpp"

HelpMenu::HelpMenu() {
    this->setTitle("Help");

    about = new QAction("About",this);
    aboutQt = new QAction("About Qt",this);

    QPixmap aboutIcon(":/icons/help-about.svg");
#ifdef NO_THEME_ICONS
    about->setIcon(aboutIcon);
#else
    about->setIcon(QIcon::fromTheme("help-about",aboutIcon));
#endif

    connect(about,SIGNAL(triggered(bool)),this,SLOT(onAboutClicked()));
    connect(aboutQt,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

    this->addAction(about);
    this->addAction(aboutQt);
}

HelpMenu::~HelpMenu() {
    delete about;
    delete aboutQt;
}

void HelpMenu::onAboutClicked() {
    QMessageBox msg;
    msg.setText("CppMediaPlayer\n"
                "A music and video player written in C++ using Qt.\n\n");
    msg.exec();
}
