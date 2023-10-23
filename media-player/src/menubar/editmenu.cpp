//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QMenu>
#include <QAction>
#include <QPixmap>

#include "editmenu.hpp"
#include "../settings/settings_dialog.hpp"

EditMenu::EditMenu() {
	this->setTitle("Edit");
	
    settings = new QAction("Settings",this);

    QPixmap settingsIcon(":/icons/preferences-system.svg");
    settings->setIcon(QIcon::fromTheme("preferences-system",settingsIcon));
	
    connect(settings,&QAction::triggered,this,&EditMenu::onSettingsClicked);
	
	this->addAction(settings);
}

EditMenu::~EditMenu() {
	delete settings;
}

void EditMenu::onSettingsClicked() {
	SettingsDialog diag;
	diag.exec();
}
