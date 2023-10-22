//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "cellmenu.hpp"
#include "../actions/format_actions.hpp"
#include "../tabwidget.hpp"

CellMenu::CellMenu() {
    this->setTitle("Cells");
    
    merge = new QAction("Merge Cells",this);
    unMerge = new QAction("Unmerge Cells",this);
    insCol = new QAction("Insert Column",this);
    insRow = new QAction("Insert Row",this);
    
    connect(merge,&QAction::triggered,this,&CellMenu::onMergeClicked);
    connect(unMerge,&QAction::triggered,this,&CellMenu::onUnMergeClicked);
    connect(insCol,&QAction::triggered,this,&CellMenu::onInsertCol);
    connect(insRow,&QAction::triggered,this,&CellMenu::onInsertRow);
    
    this->addAction(merge);
    this->addAction(unMerge);
    this->addAction(insCol);
    this->addAction(insRow);
}

CellMenu::~CellMenu() {
    delete merge;
    delete unMerge;
    delete insCol;
    delete insRow;
}

void CellMenu::onMergeClicked() {
    FormatActions::merge();
}

void CellMenu::onUnMergeClicked() {
    FormatActions::unMerge();
}

void CellMenu::onInsertCol() {
    FormatActions::insertCol();
}

void CellMenu::onInsertRow() {
    FormatActions::insertRow();
}

