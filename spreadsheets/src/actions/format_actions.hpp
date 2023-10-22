//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

class FormatActions {
public:
    static void bold();
    static void italic();
    static void underline();
    static void bgColor();
    static void fgColor();
    static void merge();
    static void unMerge();
    static void insertCol();
    static void insertRow();
    static void setFontFamily(QString family);
    static void setFontSize(int size);
    static void dspBorderDialog();
};


