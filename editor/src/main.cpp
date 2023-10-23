//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>
#include <QFile>
#include <QFileInfo>

#include <cstdlib>
#include <string>
#include <iostream>

#ifndef WIN32
#include <unistd.h>
#endif

#include "global.hpp"
#include "window.hpp"
#include "tabpane.hpp"
#include "editor.hpp"
#include "global/file_actions.hpp"
#include "global/recent.hpp"
#include "icon.hpp"

QSourceRepository *repository;
QSettings settings("CppEditor", "CppEditor");

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    QCoreApplication::setApplicationName("CppEditor");
    QCoreApplication::setOrganizationName("CppEditor");

    repository = new QSourceRepository;
    Recent::initRecentItems();
    Editor::updateSettings();
    IconManager::init();

    Window *window = new Window;
    window->show();

    for (int i = 1; i<argc; i++) {
        QString fullPath = QFileInfo(argv[i]).absoluteFilePath();
        Window::addFile(fullPath);
    }
#ifndef HAIKU_OS
#ifndef _WIN32
    if (getuid()==0) {
        TabPane::rootStatus->show();
    }
#endif
#endif
    return app.exec();
}

