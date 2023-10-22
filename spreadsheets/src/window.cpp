//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QMenuBar>

#include "window.hpp"
#include "maintoolbar.hpp"
#include "tabwidget.hpp"

StatusBar *Window::statusbar;

Window::Window() {
    this->setWindowTitle("CppSheets");
    this->setWindowIcon(QPixmap(":/icons/sheets.svg"));
    this->resize(1000,800);

    TabWidget *tabs = new TabWidget;
    MainToolbar *toolbar = new MainToolbar;

    QWidget *centerWidget = new QWidget;
    QVBoxLayout *centerLayout = new QVBoxLayout;
    centerLayout->setContentsMargins(0,0,0,0);
    centerWidget->setLayout(centerLayout);
    this->setCentralWidget(centerWidget);

    this->addToolBar(Qt::TopToolBarArea,toolbar);
    centerLayout->addWidget(tabs);

    filemenu = new FileMenu;
    formatMenu = new FormatMenu;
    cellMenu = new CellMenu;
    helpMenu = new HelpMenu;

    this->menuBar()->addMenu(filemenu);
    this->menuBar()->addMenu(formatMenu);
    this->menuBar()->addMenu(cellMenu);
    this->menuBar()->addMenu(helpMenu);

    statusbar = new StatusBar;
    this->setStatusBar(statusbar);
}

Window::~Window() {
    delete filemenu;
    delete formatMenu;
    delete cellMenu;
    delete helpMenu;
}

void Window::setCurrentPath(QString path) {
    statusbar->setPathLabel(path);
}

void Window::setCurrentSaved(bool saved) {
    statusbar->setSavedLabel(saved);
}

bool Window::checkSave() {
    int count = TabWidget::tabs->count();
    for (int i = 0; i<count; i++) {
        SheetWidget *sheet = TabWidget::widgetAt(i);
        if (!sheet->isSaved()) {
            QMessageBox msg;
            msg.setWindowTitle("Warning");
            msg.setText("You have unsaved files!\nDo you wish to exit?");
            msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msg.setIcon(QMessageBox::Warning);
            int ret = msg.exec();
            if (ret==QMessageBox::Yes) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

void Window::closeEvent(QCloseEvent *event) {
    if (checkSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}
