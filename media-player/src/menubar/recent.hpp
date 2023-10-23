//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QString>
#include <QVector>

class Recent {
public:
	Recent();
	~Recent();
	void addRecent(QString name);
	QVector<QString> *getRecentItems();
	void write();
private:
	QVector<QString> *recentItems;
};
