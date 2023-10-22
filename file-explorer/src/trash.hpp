//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

class Trash {
public:
    static void initPaths();
    static void trashFile(QString path);
    static void restoreFile(QString filename);
    static void deleteCurrentFile();
    static void emptyTrash();
    static QString folderPath;
private:
    static QString filePath;
    static void genTrashInfo();
};
