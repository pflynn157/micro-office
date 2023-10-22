//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QColorDialog>

#include "format_actions.hpp"
#include "../tabwidget.hpp"
#include "../parser/parser.hpp"
#include "../sheetwidget.hpp"
#include "../dialogs/border_dialog.hpp"

void FormatActions::bold() {
    SheetWidget *sheet = TabWidget::currentWidget();
    QTableWidgetItem *item = sheet->currentCell();
    QFont font = item->font();
    if (font.bold()) {
        font.setBold(false);
    } else {
        font.setBold(true);
    }
    item->setFont(font);
}

void FormatActions::italic() {
    SheetWidget *sheet = TabWidget::currentWidget();
    QTableWidgetItem *item = sheet->currentCell();
    QFont font = item->font();
    if (font.italic()) {
        font.setItalic(false);
    } else {
        font.setItalic(true);
    }
    item->setFont(font);
}

void FormatActions::underline() {
    SheetWidget *sheet = TabWidget::currentWidget();
    QTableWidgetItem *item = sheet->currentCell();
    QFont font = item->font();
    if (font.underline()) {
        font.setUnderline(false);
    } else {
        font.setUnderline(true);
    }
    item->setFont(font);
}

void FormatActions::bgColor() {
    QColor color = QColorDialog::getColor();
    SheetWidget *current = TabWidget::currentWidget();
    if (current->currentTable()->currentSelectedItems().size()==1) {
        TabWidget::currentWidget()->currentCell()->setBackground(QBrush(color));
    } else {
        auto list = current->currentTable()->currentSelectedItems();
        for (auto item : list) {
            int col = item.column();
            int row = item.row();

            QTableWidgetItem *tItem = current->currentTable()->item(row,col);
            if (tItem==nullptr) {
                tItem = new QTableWidgetItem();
                current->currentTable()->setItem(row,col,tItem);
            }
            tItem->setBackground(QBrush(color));
        }
    }
}

void FormatActions::fgColor() {
    QColor color = QColorDialog::getColor(Qt::black);
    SheetWidget *current = TabWidget::currentWidget();
    if (current->currentTable()->currentSelectedItems().size()==1) {
        TabWidget::currentWidget()->currentCell()->setForeground(QBrush(color));
    } else {
        auto list = current->currentTable()->currentSelectedItems();
        for (auto item : list) {
            int col = item.column();
            int row = item.row();

            QTableWidgetItem *tItem = current->currentTable()->item(row,col);
            if (tItem==nullptr) {
                tItem = new QTableWidgetItem();
                current->currentTable()->setItem(row,col,tItem);
            }
            tItem->setForeground(QBrush(color));
        }
    }
}

void FormatActions::merge() {
    TabWidget::currentWidget()->mergeSelected();
}

void FormatActions::unMerge() {
    TabWidget::currentWidget()->unMergeSelected();
}

void FormatActions::insertCol() {
    auto current = TabWidget::currentWidget();
    int col = current->currentCell()->column();
    current->currentTable()->insertColumn(col+1);
    current->currentTable()->loadHeaders();
    current->setSaved(false);
}

void FormatActions::insertRow() {
    auto current = TabWidget::currentWidget();
    int row = current->currentCell()->row();
    current->currentTable()->insertRow(row+1);
    current->setSaved(false);
}

void FormatActions::setFontFamily(QString family) {
    auto current = TabWidget::currentWidget();
    auto list = current->currentTable()->currentSelectedItems();

    if (list.size()==1) {
        QFont font = current->currentCell()->font();
        font.setFamily(family);
        current->currentCell()->setFont(font);
    } else {
        for (auto c : list) {
            QTableWidgetItem *item = current->currentTable()->item(c.row(),c.column());
            if (item==nullptr) {
                item = new QTableWidgetItem;
            }

            QFont font = item->font();
            font.setFamily(family);
            item->setFont(font);

            current->currentTable()->setItem(c.row(),c.column(),item);
        }
    }
}

void FormatActions::setFontSize(int size) {
    auto current = TabWidget::currentWidget();
    auto list = current->currentTable()->currentSelectedItems();

    if (list.size()==1) {
        QFont font = current->currentCell()->font();
        font.setPointSize(size);
        current->currentCell()->setFont(font);
    } else {
        for (auto c : list) {
            QTableWidgetItem *item = current->currentTable()->item(c.row(),c.column());
            if (item==nullptr) {
                item = new QTableWidgetItem;
            }

            QFont font = item->font();
            font.setPointSize(size);
            item->setFont(font);

            current->currentTable()->setItem(c.row(),c.column(),item);
        }
    }
}

void FormatActions::dspBorderDialog() {
    BorderDialog dialog;
    dialog.exec();
}

