//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QVector>

#include "sheet_item.hpp"

class XlsxParser {
public:
    static void createFile(QString filePath);
	static QStringList pages(QString file);
    static QVector<SheetItem> allItems(QString file, QString page);
    static QVector<MathItem> allMathItems(QString file, QString page);
    static void createPage(QString file, QString page);
    static bool pageExists(QString file, QString pageName);
    static void removePage(QString file, QString page);
    static void setData(QString file, QString page, QVector<SheetItem> items);
    static void setMathData(QString file, QString page, QVector<MathItem> items);
};
