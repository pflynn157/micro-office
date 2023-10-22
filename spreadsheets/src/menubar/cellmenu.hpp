//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class CellMenu : public QMenu {
    Q_OBJECT
public:
    CellMenu();
    ~CellMenu();
private:
    QAction *merge, *unMerge;
    QAction *insCol, *insRow;
private slots:
    void onMergeClicked();
    void onUnMergeClicked();
    void onInsertCol();
    void onInsertRow();
};
