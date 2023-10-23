//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QVariant>
#include <QSettings>

#include <icon.hpp>
#include <global.hpp>

bool IconManager::useSys = true;

//We use this function so we only have to read settings once
//This is called from the main function
void IconManager::init() {
    useSys = settings.value("sysicons","true").toBool();
}

QIcon IconManager::getIcon(QString name) {
    QIcon icon;
    QPixmap embed = QPixmap(":/icons/"+name+".png");
    if (useSys) {
        icon = QIcon::fromTheme(name,embed);
    } else {
        icon = QIcon(embed);
    }
    return icon;
}
