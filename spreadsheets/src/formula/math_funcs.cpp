//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <cmath>
#include <iostream>

#include "math_funcs.hpp"
#include "formula_utils.hpp"

//The logic for the SUM formula
void MathFuncs::sum(QString equ, MathItem current, TableWidget *table) {
    if (!FormulaUtils::isRange(equ)) {
        QString err = "#!SYNTAX ERROR";
        FormulaUtils::printResult(err,current,table);
        return;
    }

    QStringList range = FormulaUtils::rangeContents(equ,table);

    double answer = 0;

    for (int i = 0; i<range.size(); i++) {
        double c = QVariant(range.at(i)).toDouble();
        answer+=c;
    }

    FormulaUtils::printResult(answer,current,table);
}

//The logic for the AVERAGE formula
double MathFuncs::average(QString equ, TableWidget *table) {
    //First, get our contents
    //We will push them all too a QStringList
    QStringList contents;

    //See if we have a range or a list, and go from there
    if (equ.contains(":")) {
        contents = FormulaUtils::rangeContents(equ,table);
    } else {
        //Break up the equation
        QString current = "";

        for (QChar c : equ) {
            if (c==',') {
                contents << current;
                current = "";
            } else {
                current+=c;
            }
        }

        contents << current;

        //Now go through and make sure we aren't referencing cells
        QStringList tmp;

        for (QString ln : contents) {
            if (ln.at(0).isLetter()) {
                ln = FormulaUtils::cellFromName(ln,table).content;
            }
            tmp << ln;
        }

        contents = tmp;
    }

    //Average is the sum of all numbers divided by the number of numbers
    //Now, calculate and return
    double len = contents.size();
    double sum = 0;

    for (QString ln : contents) {
        double no = QVariant(ln).toDouble();
        sum+=no;
    }

    double result = sum/len;
    return result;
}

//The logic for the ABS formula
double MathFuncs::abs(QString equ, TableWidget *table) {
    //Convert to a number
    double no = getInner(equ,table);

    //Calculate and return
    double result = std::abs(no);
    return result;
}

//The logic for the POWER formula
double MathFuncs::pow(QString equ, TableWidget *table) {
    //First, separate the string
    QString part1 = "", part2 = "";
    bool found = false;

    for (QChar c : equ) {
        if (c==',') {
            found = true;
        } else {
            if (found) {
                part1+=c;
            } else {
                part2+=c;
            }
        }
    }

    //If either of the strings start with a letter, we have a cell
    //Otherwise, we have a number
    if (part1.at(0).isLetter()) {
        part1 = FormulaUtils::cellFromName(part1,table).content;
    }

    if (part2.at(0).isLetter()) {
        part2 = FormulaUtils::cellFromName(part2,table).content;
    }

    //Now, convert both to numbers
    //In case we have decimals, we want doubles
    double no1 = QVariant(part1).toDouble();
    double no2 = QVariant(part2).toDouble();

    //Calculate
    double result = std::pow(no2,no1);
    return result;
}

//The logic for the ACOS formula
double MathFuncs::acos(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::acos(no);
}

//The logic for the ACOSH formula
double MathFuncs::acosh(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::acosh(no);
}

//The logic for the COS formula
double MathFuncs::cos(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::cos(no);
}

//The logic for the SIN formula
double MathFuncs::sin(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::sin(no);
}

//The logic for the TAN formula
double MathFuncs::tan(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::tan(no);
}

//The logic for the SQRT formula
double MathFuncs::sqrt(QString equ, TableWidget *table) {
    double no = getInner(equ,table);
    return std::sqrt(no);
}

//Returns the equ part of a formula
double MathFuncs::getInner(QString equ, TableWidget *table) {
    double ret = 0;
    QString ln = equ;

    if (equ.at(0).isLetter()) {
        ln = FormulaUtils::cellFromName(equ,table).content;
    }

    ret = QVariant(ln).toDouble();

    return ret;
}
