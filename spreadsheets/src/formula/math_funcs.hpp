//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

#include "../tablewidget.hpp"

class MathFuncs {
public:
    static void sum(QString equ, MathItem current, TableWidget *table);
    static double average(QString equ, TableWidget *table);
    static double abs(QString equ, TableWidget *table);
    static double pow(QString equ, TableWidget *table);
    static double acos(QString equ, TableWidget *table);
    static double acosh(QString equ, TableWidget *table);
    static double cos(QString equ, TableWidget *table);
    static double sin(QString equ, TableWidget *table);
    static double tan(QString equ, TableWidget *table);
    static double sqrt(QString equ, TableWidget *table);
private:
    static double getInner(QString equ, TableWidget *table);
};
