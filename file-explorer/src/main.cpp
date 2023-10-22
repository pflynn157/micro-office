//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>

#include "window.hpp"
#include "clipboard.hpp"
#include "trash.hpp"

Clipboard clipboard;

int main(int argc, char *argv[]) {
    //Settings::registerApp("cpp-explorer");
    //Settings::setDefaultSettingsFile(":/rsc/settings.xml");
    //Settings::initPaths();

    QApplication a(argc, argv);

    Trash::initPaths();

    Window w;
    w.show();

    return a.exec();
}
