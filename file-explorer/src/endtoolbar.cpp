//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>

#include "endtoolbar.hpp"
#include "window.hpp"

EndToolbar::EndToolbar()
    : showTxtAddr(new QToolButton),
      iconView(new QToolButton),
      listView(new QToolButton)
{
    this->setMovable(false);

    showTxtAddr->setIcon(QIcon::fromTheme("insert-text",QPixmap(":/icons/document-edit.svg")));
    iconView->setIcon(QIcon::fromTheme("view-list-icons",QPixmap(":/icons/view-list-icons.svg")));
    listView->setIcon(QIcon::fromTheme("view-list-details",QPixmap(":/icons/view-list-details.svg")));

    connect(showTxtAddr,&QToolButton::clicked,this,&EndToolbar::onShowTxtAddr);
    connect(iconView,&QToolButton::clicked,this,&EndToolbar::onIconViewClicked);
    connect(listView,&QToolButton::clicked,this,&EndToolbar::onListViewClicked);

    this->addWidget(showTxtAddr);
    this->addWidget(iconView);
    this->addWidget(listView);

    this->resize(this->minimumSize());
}

EndToolbar::~EndToolbar() {
    delete showTxtAddr;
    delete iconView;
    delete listView;
}

void EndToolbar::setBrowserWidget(BrowserWidget *b) {
    bWidget = b;
}

void EndToolbar::onShowTxtAddr() {
    if (Window::addrTxt->isVisible()) {
        Window::addrTxt->hide();
        Window::addrButtons->show();
    } else {
        Window::addrTxt->show();
        Window::addrButtons->hide();
    }
}

void EndToolbar::onIconViewClicked() {
    if (bWidget==nullptr) {
        return;
    }
    bWidget->setIconView();
}

void EndToolbar::onListViewClicked() {
    if (bWidget==nullptr) {
        return;
    }
    bWidget->setListView();
}
