//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "searchbar.hpp"

SearchBar::SearchBar(BrowserWidget *b)
    : layout(new QHBoxLayout),
      label(new QLabel("Search")),
      entry(new QLineEdit),
      close(new QPushButton("Close"))
{
    bWidget = b;

    this->setLayout(layout);

    entry->setClearButtonEnabled(true);

    layout->addWidget(label);
    layout->addWidget(entry);
    layout->addWidget(close,0,Qt::AlignRight);

    connect(entry,&QLineEdit::returnPressed,this,&SearchBar::onEnterPressed);
    connect(close,&QPushButton::clicked,this,&SearchBar::onCloseClicked);
}

SearchBar::~SearchBar() {
    delete layout;
    delete entry;
    delete close;
}

void SearchBar::onEnterPressed() {
    bWidget->reload();
    bWidget->searchPatterns.clear();
    bWidget->searchPatterns.append(entry->text());
    bWidget->reload();
}

void SearchBar::onCloseClicked() {
    bWidget->searchPatterns.clear();
    bWidget->reload();
    this->hide();
}
