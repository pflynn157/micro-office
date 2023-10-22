//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QVector>

#include "math_types.hpp"
#include "../parser/sheet_item.hpp"
#include "../tablewidget.hpp"

class Math {
public:
    static void updateMath(QVector<MathItem> mathItems, TableWidget *table);
    static bool interpret(QString name, QString equ, MathItem current, TableWidget *table);
    static void solveIF(QString statement, MathItem current, TableWidget *table);
    static void solveColumn(MathItem current, TableWidget *table);
};
