//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>

#include "tinyxml2.h"
#include "sheet_item.hpp"

using namespace tinyxml2;

class XmlParser {
public:
    static void createFile(QString filePath);
	static QStringList pages(QString file);
    static QVector<SheetItem> allItems(QString file, QString page);
    static QVector<MathItem> allMathItems(QString file, QString page);
    static QVector<GraphItem> allGraphItems(QString file, QString page);
    static void createPage(QString file, QString page);
    static bool pageExists(QString file, QString pageName);
    static void removePage(QString file, QString page);
    static void setData(QString file, QString page, QVector<SheetItem> items);
    static void setMathData(QString file, QString page, QVector<MathItem> items);
    static void setGraphData(QString file, QString page, QVector<GraphItem> items);
    static XMLElement *getPageElement(XMLElement *root, QString title);
};
