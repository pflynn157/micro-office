//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QHeaderView>
#include <QTableWidgetItem>

#include "formula_utils.hpp"
#include "../tablewidget.hpp"

//This returns the formula's name.
QString FormulaUtils::formulaName(QString equation) {
    QString name = "";

    int start = 0;
    if (equation.at(0)=='=') {
        start = 1;
    }

    for (int i = start; i<equation.length(); i++) {
        if (equation.at(i)=='(') {
            break;
        }
        name+=equation.at(i);
    }

    return name;
}

//This returns the formula's content
QString FormulaUtils::formulaEqu(QString equation) {
    QString ret = "";
    bool in = false;

    for (int i = 1; i<equation.length(); i++) {
        if (equation.at(i)=='(' && !in) {
            in = true;
        } else {
            if (in) {
                ret+=equation.at(i);
            }
        }
    }

    ret = ret.remove(ret.length()-1,ret.length()-1);

    return ret;
}

//All the items within a particular rnage
QStringList FormulaUtils::rangeContents(QString range, TableWidget *table) {
    QStringList ret;

    //First, break up the range
    QString start = "";
    QString end = "";
    bool found = false;

    for (int i = 0; i<range.length(); i++) {
        if (range.at(i)==':') {
            found = true;
        } else {
            if (found) {
                end+=range.at(i);
            } else {
                start+=range.at(i);
            }
        }
    }

    //Get cell locations and contents
    Cell startC = cellFromName(start,table);
    Cell endC = cellFromName(end,table);

    //Now, we must see which direction we are going (horizontal or vertical)
    ret.push_back(startC.content);

    if (startC.x!=endC.x) {
        //We are going across
        for (int i = startC.x+1; i<=endC.x; i++) {
            QTableWidgetItem *item = table->item(startC.y,i);
            if (item!=nullptr) {
                ret.push_back(item->text());
            }
        }
    } else {
        //We are going vertically
        for (int i = startC.y+1; i<endC.y; i++) {
            QTableWidgetItem *item = table->item(i,startC.x);
            if (item!=nullptr) {
                ret.push_back(item->text());
            }
        }
    }

    ret.push_back(endC.content);

    //Go through the list and remove and blank entries
    QStringList list2;

    for (int i = 0; i<ret.size(); i++) {
        QString current = ret.at(i);
        if (current.length()>0) {
            list2.push_back(current);
        }
    }

    ret = list2;

    return ret;
}

Cell FormulaUtils::cellFromName(QString name, TableWidget *table) {
    Cell c;

    //Make sure the name is trimmed
    name = name.trimmed();

    //Separate the string into parts
    QString part1 = "";
    QString part2 = "";

    for (int i = 0; i<name.length(); i++) {
        if (name.at(i).isNumber()) {
            part2+=name.at(i);
        } else {
            part1+=name.at(i);
        }
    }

    //Part 1 corresponds to the X var, so get the header that
    //matches the part1 var
    int h_count = table->horizontalHeader()->count();
    for (int i = 0; i<h_count; i++) {
        if (table->horizontalHeaderItem(i)->text()==part1) {
            c.x = i;
            break;
        }
    }

    //Part 2 corresponds to the Y var, so go ahead and convert
    c.y = QVariant(part2).toInt();
    c.y = c.y-1;

    //We now have a valid location. Get the content.
    QTableWidgetItem *item = table->item(c.y,c.x);
    if (item==nullptr) {
        c.content = "";
    } else {
        c.content = item->text();
    }

    return c;
}

//This prints the results of our calculations to the table
void FormulaUtils::printResult(QString answer, MathItem current, TableWidget *table) {
    QTableWidgetItem *item = table->item(current.x,current.y);
    if (item==nullptr) {
        item = new QTableWidgetItem;
    }
    item->setText(answer);
    table->setItem(current.x,current.y,item);
}

void FormulaUtils::printResult(double answer, MathItem current, TableWidget *table) {
    QString answerStr = QVariant(answer).toString();
    printResult(answerStr,current,table);
}

//Checks to see if an equation is a range
bool FormulaUtils::isRange(QString equation) {
   //First, see if we have a colon
    if (!equation.contains(":") || equation.count(":") > 1) {
        return false;
    }

    //So we have a single colon
    //Now break up the string and make sure we have valid cells
    QString part1 = "";
    QString part2 = "";
    bool found = false;

    for (QChar c : equation) {
        if (c == ':') {
            found = true;
        } else {
            if (found) {
                part2 += c;
            } else {
                part1 += c;
            }
        }
    }

    part1 = part1.trimmed();
    part2 = part2.trimmed();

    if (part1.at(0).isLetter() && part1.at(part1.length()-1).isNumber()) {
        if (part2.at(0).isLetter() && part2.at(part2.length()-1).isNumber()) {
           return true;
        }
    }

    return false;
}

//Checks to see if we have a column equation
bool FormulaUtils::isColumnEqu(QString equation) {
    if (equation.contains("+") || equation.contains("-")
            || equation.contains("*") || equation.contains("/")) {
        return true;
    }

    return false;
}

