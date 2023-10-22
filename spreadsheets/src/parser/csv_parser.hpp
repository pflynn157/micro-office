//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QVector>
#include <QString>

#include "sheet_item.hpp"

class CsvParser {
public:
    static QVector<SheetItem> allItems(QString file, QString page);
    static void setData(QString file, QString page, QVector<SheetItem> items);
private:
    static QStringList fileLines(QString file);
    static QStringList lineParts(QString line);
};
