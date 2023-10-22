//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "str_funcs.hpp"
#include "formula_utils.hpp"

//The code for the LEN formula
QString StrFuncs::len(QString equ, TableWidget *table) {
    QString ln = getInner(equ,table);

    if (ln!="ERR") {
        ln = QVariant(ln.length()).toString();
    }

    return ln;
}

//The code for the UPPER formula
QString StrFuncs::upper(QString equ, TableWidget *table) {
    QString ln = getInner(equ,table);

    if (ln!="ERR") {
        ln = ln.toUpper();
    }

    return ln;
}

//The code for the LOWER formula
QString StrFuncs::lower(QString equ, TableWidget *table) {
    QString ln = getInner(equ,table);

    if (ln!="ERR") {
        ln = ln.toLower();
    }

    return ln;
}

//Returns the inside of String functions
QString StrFuncs::getInner(QString equ, TableWidget *table) {
    QString ln = "";

    if (equ.at(0)=='\"' && equ.at(equ.length()-1)=='\"') {
        ln = equ;
        ln.remove(0,1);
        ln.remove(ln.length()-1,ln.length()-1);
    } else if (equ.at(0).isLetter()) {
        ln = FormulaUtils::cellFromName(equ,table).content;
    } else {
        ln = "ERR";
    }

    return ln;
}
