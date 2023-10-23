//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QIcon>

class IconManager {
public:
    static void init();
    static QIcon getIcon(QString name);
private:
    static bool useSys;
};
