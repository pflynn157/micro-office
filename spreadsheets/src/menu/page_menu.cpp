//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "page_menu.hpp"
#include "../tabwidget.hpp"
#include "../sheetwidget.hpp"

PageMenu::PageMenu() {
    copy = new QAction("Copy",this);
    rename = new QAction("Rename",this);

    connect(copy,&QAction::triggered,this,&PageMenu::onCopyClicked);
    connect(rename,&QAction::triggered,this,&PageMenu::onRenameClicked);

    this->addAction(copy);
    this->addAction(rename);
}

PageMenu::~PageMenu() {
    delete copy;
    delete rename;
}

void PageMenu::onCopyClicked() {
    auto current = TabWidget::currentWidget();
    QString oldPage = current->currentPage();
    current->insertPage();

    auto data = current->data(oldPage);
    auto mathData = current->mathData(oldPage);
    current->setData(data,current->currentTable());
    current->currentTable()->setMathItems(mathData);
}

void PageMenu::onRenameClicked() {
    int current = TabWidget::currentWidget()->currentIndex();
    TabWidget::currentWidget()->renamePage(current);
}
