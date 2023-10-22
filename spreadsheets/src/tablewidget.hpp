//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QTableWidget>
#include <QItemDelegate>
#include <QPainter>
#include <QVector>
#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QKeyEvent>

#include "parser/xml_parser.hpp"

class TableWidget : public QTableWidget {
    Q_OBJECT
public:
    TableWidget();
    void loadHeaders();
    void setMathItems(QVector<MathItem> items);
    void addMathItem(MathItem item);
    QVector<MathItem> allMathItems();
    void updateMath();
    bool isMath(int row, int col);
    QString formula(int row, int col);
    QModelIndexList currentSelectedItems();
    void addGraphItem(GraphItem item);
    QVector<GraphItem> allGraphItems();
private:
    void keyPressEvent(QKeyEvent *event);
private:
    QVector<MathItem> mathItems;
    QVector<GraphItem> graphItems;
private slots:
    void onCellChanged();
    void onItemChanged(QTableWidgetItem *item);
    void onCellClicked(int row, int col);
    void onCurrentCellChanged(int currentRow, int currentCol, int oldRow, int oldCol);
signals:
    void cellModified();
};
