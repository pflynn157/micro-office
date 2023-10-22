//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QItemDelegate>
#include <QPainter>

class TableWidgetDelegate : public QItemDelegate {
    Q_OBJECT
public:
    explicit TableWidgetDelegate(QObject *parent);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
