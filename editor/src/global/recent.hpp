//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QStringList>

class Recent {
public:
    static void initRecentItems();
    static void addRecentItem(QString item);
    static QStringList *allItems();
    static void write();
    static void clearAll();
    static QString recentFilePath();
private:
    static QString filePath;
    static QStringList *items;
};
