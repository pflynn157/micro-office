//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>
#include <QCoreApplication>
#include <QPixmap>

#include "window.hpp"
#include "videopane.hpp"
#include "global.hpp"

Vars globalVars;

int main(int argc, char *argv[]) {
    //Settings::registerApp("cpp-media-player");
    //Settings::setDefaultSettingsFile(":/rsc/settings.xml");
    //Settings::initPaths();

    QApplication app(argc,argv);

    QCoreApplication::setOrganizationName("CppMediaPlayer");
    QCoreApplication::setApplicationName("CppMediaPlayer");

    globalVars.window = new Window();
    //globalVars.window->showMaximized();
    globalVars.window->show();

    if (argc>1) {
        QString entry = argv[1];
        //VideoPane::player->setMedia(QMediaContent(QUrl::fromLocalFile(entry)));
        VideoPane::startPlaying();
    }

    return app.exec();
}
