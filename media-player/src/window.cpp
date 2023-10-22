//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QKeyEvent>
#include <QApplication>
#include <QPixmap>
#include <QVariant>
#include <QMenuBar>

#include "window.hpp"
#include "videopane.hpp"
#include "menubar/filemenu.hpp"
#include "menubar/editmenu.hpp"
#include "menubar/viewmenu.hpp"
#include "menubar/helpmenu.hpp"
#include "actions.hpp"

PlayList *Window::playlist;

Window::Window() {
    this->setWindowTitle("Media Player");
    this->resize(900,700);
    this->setAttribute(Qt::WA_QuitOnClose);

    QPixmap winIcon(":/icons/cpp-media-player.svg");
    this->setWindowIcon(QIcon::fromTheme("applications-multimedia",winIcon));

    FileMenu *fileMenu = new FileMenu;
    EditMenu *editMenu = new EditMenu;
    ViewMenu *viewMenu = new ViewMenu;
    HelpMenu *helpMenu = new HelpMenu;

    this->menuBar()->setContextMenuPolicy(Qt::PreventContextMenu);
    this->menuBar()->addMenu(fileMenu);
    this->menuBar()->addMenu(editMenu);
    this->menuBar()->addMenu(viewMenu);
    this->menuBar()->addMenu(helpMenu);
    
    playlist = new PlayList;
    playlist->hide();
    this->addDockWidget(Qt::LeftDockWidgetArea,playlist);

    QWidget *videopanel = new QWidget;
    videopanel->setStyleSheet("background-color:black;");
    
    QVBoxLayout *videolayout = new QVBoxLayout;
    videopanel->setLayout(videolayout);
    this->setCentralWidget(videopanel);

    videopane = new VideoPane;
    videolayout->addWidget(videopane);

    controller = new ControlBar;
    this->addToolBar(Qt::BottomToolBarArea,controller);

    systray = new SysTray;
    //if (QVariant(Settings::getSetting("taskbar/icon","true")).toBool()) {
    //    systray->show();
    //} else {
    //    systray->hide();
    //}
    systray->show();
    
    isHeadless = false;
}

void Window::setHeadless(bool headless) {
	if (headless) {
        this->menuBar()->hide();
		playlist->hide();
		controller->hide();
	} else {
        this->menuBar()->show();
		playlist->show();
		controller->show();
	}
}

void Window::dspPlaylist() {
    if (playlist->isVisible()) {
        playlist->hide();
    } else {
        playlist->show();
    }
}

void Window::keyPressEvent(QKeyEvent *event) {
	if ((event->modifiers()==Qt::ControlModifier)and(event->key()==Qt::Key_Q)) {
		qApp->exit();
	} else if ((event->modifiers()==Qt::ControlModifier)and(event->key()==Qt::Key_O)) {
		Actions::open();
	} else if (event->key()==Qt::Key_F11) {
		Actions::setWindowFullscreen();
	} else if ((event->modifiers()==Qt::ControlModifier)and(event->key()==Qt::Key_H)) {
		if (isHeadless) {
			isHeadless = false;
		} else {
			isHeadless = true;
		}
		this->setHeadless(isHeadless);
	}
}

void Window::closeEvent(QCloseEvent *event) {
    delete systray;
    event->accept();
}
