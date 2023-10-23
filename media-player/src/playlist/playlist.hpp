//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDockWidget>
#include <QTabWidget>

class PlayList : public QDockWidget {
	Q_OBJECT
public:
	PlayList();
	~PlayList();
private:
	QTabWidget *tabs;
}; 
