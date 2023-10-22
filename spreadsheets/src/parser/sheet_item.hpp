//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QColor>
#include <QFont>
#include <QList>

struct SheetItem {
    int x;
    int y;
    QString data;
    QColor bgColor;
    QColor fgColor;
    QString tooltip;
    int colWidth;
    int rowWidth;
    int spanx;
    int spany;
    QFont font;
    QString border;
};

struct MathItem {
    int x;
    int y;
    QString equation;
};

//Graph types
enum GraphType {
    BAR = 1,
    PIE = 2
};

//Graph sets
struct GraphSet {
    QString name;
    QString range;
};

struct GraphItem {
    QString name;
    GraphType type;
    QStringList categories;
    QList<GraphSet> sets;
};
