//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QString>
#include <QVector>
#include <QList>

#include "filemenu.hpp"
#include "../actions.hpp"
#include "recent.hpp"
#include "recent_action.hpp"

QMenu *FileMenu::recent;

FileMenu::FileMenu() {
	this->setTitle("File");

    open = new QAction("Open",this);
	recent = new QMenu("Recent");
    quit = new QAction("Quit",this);

    QPixmap openIcon(":/icons/document-open.svg");
    QPixmap quitIcon(":/icons/window-close.svg");

    open->setIcon(QIcon::fromTheme("document-open",openIcon));
    quit->setIcon(QIcon::fromTheme("window-close",quitIcon));

    connect(open,&QAction::triggered,this,&FileMenu::onOpenClicked);
    connect(quit,&QAction::triggered,qApp,&QApplication::quit);

    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    quit->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
	
	refreshRecentEntries();

	this->addAction(open);
	this->addMenu(recent);
	this->addAction(quit);
}

FileMenu::~FileMenu() {
	delete open;
	delete recent;
	delete quit;
}

void FileMenu::refreshRecentEntries() {
	QList<QAction *> menuActions = recent->actions();
    if (!menuActions.empty()) {
		for (int i = 0; i<menuActions.size(); i++) {
			recent->removeAction(menuActions.at(i));
		}
	}
	Recent *recentItems = new Recent;
	QVector<QString> *items = recentItems->getRecentItems();
	if (items->size()==0) {
		QAction *none = new QAction("None",recent);
		none->setEnabled(false);
		recent->addAction(none);
	} else {
		QVector<QString> *to_add = new QVector<QString>();
		for (int i = 0; i<items->size(); i++) {
			to_add->push_back(items->at(i));
		}
		for (int i = 0; i<to_add->size(); i++) {
			recent->addAction(new RecentAction(to_add->at(i),recent));
		}
	}
}

void FileMenu::onOpenClicked() {
	Actions::open();
}
