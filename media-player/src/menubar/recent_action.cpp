//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QAction>
#include <QString>
#include <QWidget>
#include <QUrl>

#include "recent_action.hpp"
#include "../videopane.hpp"
#include "recent.hpp"
#include "filemenu.hpp"

RecentAction::RecentAction(QString text, QWidget *parent) : QAction(parent) {
	this->setText(text);
	connect(this,SIGNAL(triggered(bool)),this,SLOT(onClicked()));
}

void RecentAction::onClicked() {
	Recent recent;
	recent.addRecent(this->text());
	recent.write();
	FileMenu::refreshRecentEntries();
	//VideoPane::player->setMedia(QMediaContent(QUrl::fromLocalFile(this->text())));
	VideoPane::player->play();
}
