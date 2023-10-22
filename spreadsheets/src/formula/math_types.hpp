//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>

enum OPERATION {
    ADD,
    SUB,
    MP,
    DIV
};

struct Cell {
    int x;
    int y;
    QString content;
};
