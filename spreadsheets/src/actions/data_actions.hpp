//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QVector>

#include "../parser/sheet_item.hpp"

struct DataItem {
    SheetItem item;
    int original_row;
    int original_col;
};

class DataActions {
public:
    static void load_clipboard(bool cut_data);
    static void paste_data();
private:
    static DataItem clipboard1;
    static QVector<DataItem> clipboard;
    static bool cut;

    static void paste_single_item(int dest_row, int dest_col);
};
