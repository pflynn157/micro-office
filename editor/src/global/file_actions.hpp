//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

class FileActions {
public:
    static void newFile();
    static void openFile();
    static void processOpenFile(QString file);
    static void saveFile(QString path);
    static void saveFile();
    static void saveFileAs();
    static QString fileContents(QString path);
};
