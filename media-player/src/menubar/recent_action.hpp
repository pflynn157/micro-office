//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QAction>
#include <QString>
#include <QWidget>

class RecentAction : public QAction {
	Q_OBJECT
public:
	RecentAction(QString text, QWidget *parent);
private slots:
	void onClicked();
};
