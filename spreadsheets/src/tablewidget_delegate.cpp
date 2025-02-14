//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QTableWidgetItem>

#include "tablewidget_delegate.hpp"
#include "tabwidget.hpp"

TableWidgetDelegate::TableWidgetDelegate(QObject *parent) : QItemDelegate(parent) {
}

void TableWidgetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    //Syntax: border:<color>,<width>,<type>
    //Types:
    //solid
    //dash
    //dot
    //dash_dot
    //dash_dot_dot
    if (index.data(Qt::UserRole).toString().startsWith("border:")) {
        QString s = index.data(Qt::UserRole).toString();
        QString colorStr = "NULL";
        QString widthStr = "NULL";
        QString typeStr = "NULL";

        QString current = "";
        int cNo = 1;
        for (int i = 0; i<s.length(); i++) {
            if (s.at(i)==':') {
                for (int j = i+1; j<s.length(); j++) {
                    if (s.at(j)==',') {
                        if (cNo==1) {
                            colorStr = current;
                        } else if (cNo==2) {
                            widthStr = current;
                        } else if (cNo==3) {
                            typeStr = current;
                        }
                        current = "";
                        cNo++;
                    } else {
                        current+=s.at(j);
                    }
                }
            }
        }
        if (cNo==3) {
            typeStr = current;
        }

        if (colorStr=="NULL" || widthStr=="NULL" || typeStr=="NULL") {
            QItemDelegate::paint(painter,option,index);
            return;
        }

        QColor color(colorStr);
        QBrush brush(color);
        int width = QVariant(widthStr).toInt();

        Qt::PenStyle type = Qt::SolidLine;
        if (typeStr=="dash") {
            type = Qt::DashLine;
        } else if (typeStr=="dot") {
            type = Qt::DotLine;
        } else if (typeStr=="dash_dot") {
            type = Qt::DashDotLine;
        } else if (typeStr=="dash_dot_dot") {
            type = Qt::DashDotDotLine;
        }

        painter->save();
        QPen pen(brush, width, type, Qt::SquareCap, Qt::MiterJoin);
        int w = pen.width()/2;
        painter->setPen(pen);
        painter->setBrush(Qt::white);
        painter->drawRect(option.rect.adjusted(w,w,-w,-w));
        painter->restore();

        QItemDelegate::paint(painter,option,index);

    //Controls the brush for currently-selected cells
    } else if (option.state & QStyle::State_Selected) {
        //First, get the current cell and the saved state
        bool saved = TabWidget::currentWidget()->isSaved();
        QTableWidgetItem *item = TabWidget::currentWidget()->currentCell();

        //Set the brush for the background
        painter->save();
        QPen pen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
        int w = pen.width()/2;
        painter->setPen(pen);
        painter->setBrush(item->background());
        painter->drawRect(option.rect.adjusted(w-1,w,-w,-w));
        painter->restore();

        //Set the brush for the text
        //TODO: Somehow add some padding around the text
        painter->save();
        QPen pen2(item->foreground().color());
        painter->setPen(pen2);
        painter->setFont(item->font());
        painter->drawText(option.rect,Qt::AlignVCenter,index.data().toString());
        painter->restore();

        TabWidget::currentWidget()->setSaved(saved);
    } else {
        QItemDelegate::paint(painter,option,index);
    }
}
