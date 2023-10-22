//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QStringList>

enum Clipboard_Actions {
    CUT,
    COPY,
    NONE
};

struct Clipboard {
    QStringList fileName;
    QString oldPath;
    QString newPath;
    Clipboard_Actions action;
};

extern Clipboard clipboard;
