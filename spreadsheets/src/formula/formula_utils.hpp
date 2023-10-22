//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

#include "math_types.hpp"
#include "../tablewidget.hpp"

class FormulaUtils {
public:
    static QString formulaName(QString equation);
    static QString formulaEqu(QString equation);
    static QStringList rangeContents(QString range, TableWidget *table);
    static Cell cellFromName(QString name, TableWidget *table);
    static void printResult(QString answer, MathItem current, TableWidget *table);
    static void printResult(double answer, MathItem current, TableWidget *table);
    static bool isRange(QString equation);
    static bool isColumnEqu(QString equation);
};
