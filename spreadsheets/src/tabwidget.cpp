//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFileInfo>
#include <QMessageBox>

#include "tabwidget.hpp"
#include "window.hpp"

QTabWidget *TabWidget::tabs;

TabWidget::TabWidget()
    : layout(new QVBoxLayout)
{
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    tabs->setTabBarAutoHide(true);
    tabs->setTabsClosable(true);
    tabs->setMovable(true);

    tabs->addTab(new SheetWidget("untitled"),"untitled");
    layout->addWidget(tabs);

    connect(tabs,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabCloseRequested(int)));
    connect(tabs,&QTabWidget::currentChanged,this,&TabWidget::onCurrentChanged);
}

TabWidget::~TabWidget() {
    delete layout;
}

void TabWidget::addNewTab() {
    int count = tabs->count();
    tabs->addTab(new SheetWidget("untitled"),"untitled");
    tabs->setCurrentIndex(count);

    Window::setCurrentPath("untitled");
    Window::setCurrentSaved(true);
}

void TabWidget::addNewTab(QString file) {
    int count = tabs->count();
    SheetWidget *sheet = new SheetWidget(file);
    sheet->loadFile();
    tabs->addTab(sheet,QFileInfo(file).fileName());
    tabs->setCurrentIndex(count);

    Window::setCurrentPath(file);
    Window::setCurrentSaved(true);
}

SheetWidget *TabWidget::currentWidget() {
    SheetWidget *widget = static_cast<SheetWidget *>(tabs->currentWidget());
    return widget;
}

SheetWidget *TabWidget::widgetAt(int index) {
    SheetWidget *widget = static_cast<SheetWidget *>(tabs->widget(index));
    return widget;
}

void TabWidget::setCurrentTitle(QString title) {
    tabs->setTabText(tabs->currentIndex(),title);
}

void TabWidget::onTabCloseRequested(int index) {
    if (tabs->count()==1) {
        addNewTab();
    }
    auto widget = widgetAt(index);
    if (widget->isSaved()) {
        delete widget;
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("This file has not been saved.\n"
                    "Do you wish to close it?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msg.exec();
        if (ret==QMessageBox::Yes) {
            delete widget;
        }
    }
}

void TabWidget::onCurrentChanged() {
    Window::setCurrentPath(currentWidget()->file());
    Window::setCurrentSaved(currentWidget()->isSaved());
}
