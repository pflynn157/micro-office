//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFile>
#include <QDir>
#include <QTextStream>

#include "recent.hpp"
#include "../menubar/filemenu.hpp"

QStringList *Recent::items;
QString Recent::filePath;

void Recent::initRecentItems() {
    items = new QStringList;

    QString path = QDir::homePath();
#ifdef _WIN32
    if (!path.endsWith("\\")) {
        path+="\\";
    }
#else
    if (!path.endsWith("/")) {
        path+="/";
    }
#endif
#ifdef HAIKU_OS
	path+="config/settings/CppEditor";
#elif _WIN32
    path+="\\AppData\\Local\\CppEditor";
#else
    path+=".CppEditor";
#endif
    if (!QDir(path).exists()) {
        QDir().mkpath(path);
    }
#ifdef _WIN32
    path+="\\recent.txt";
#else
    path+="/recent";
#endif
    filePath = path;

    QFile file(filePath);
    if (file.open(QFile::ReadWrite)) {
        QTextStream reader(&file);
        while (!reader.atEnd()) {
            items->push_back(reader.readLine());
        }
        file.close();
    }
}

void Recent::addRecentItem(QString item) {
    if (items->size()>10) {
        for (int i = 10; i<items->size(); i++) {
            items->removeAt(i);
        }
    }
    if (items->size()==10) {
        items->removeFirst();
    }
    items->push_back(item);
    Recent::write();
    FileMenu::recentMenu->loadEntries();
}

QStringList *Recent::allItems() {
    return items;
}

void Recent::write() {
    QFile file(filePath);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writer(&file);
        for (int i = 0; i<items->size(); i++) {
            writer << items->at(i)+"\n";
        }
        file.resize(writer.pos());
        file.close();
    }
}

void Recent::clearAll() {
    items->clear();
}

QString Recent::recentFilePath() {
    return filePath;
}
