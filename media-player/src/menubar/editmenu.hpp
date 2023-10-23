//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class EditMenu : public QMenu {
	Q_OBJECT
public:
	EditMenu();
	~EditMenu();
private:
	QAction *settings;
private slots:
	void onSettingsClicked();
};
