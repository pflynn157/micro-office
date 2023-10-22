//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

#include "../tablewidget.hpp"

class StrFuncs {
public:
    static QString len(QString equ, TableWidget *table);
    static QString upper(QString equ, TableWidget *table);
    static QString lower(QString equ, TableWidget *table);
private:
    static QString getInner(QString equ, TableWidget *table);
};
