//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QString>
#include <QVector>
#include <QDir>
#include <QFile>
#include <string>
#include <fstream>
#include <iostream>

#include "recent.hpp"

using std::string;
using std::ifstream;
using std::getline;
using std::ofstream;
using std::endl;

Recent::Recent() {
	recentItems = new QVector<QString>();
	QString path = QDir::homePath();
    path+="/.cpp-media-player";
    if (!QDir(path).exists()) {
        QDir().mkpath(path);
	}
    path+="/recent";
    ifstream reader(path.toStdString().c_str());
    if (reader.is_open()) {
        string line = "";
        while (getline(reader,line)) {
            recentItems->push_back(QString::fromStdString(line));
        }
        reader.close();
    }
}

Recent::~Recent() {
	delete recentItems;
}

void Recent::addRecent(QString name) {
	if (recentItems->size()==5) {
		recentItems->remove(4);
	}
	recentItems->push_front(name);
}

QVector<QString> *Recent::getRecentItems() {
	return recentItems;
}

void Recent::write() {
	QString path1 = QDir::homePath();
    path1+="/.cpp-media-player";
	if (not QDir(path1).exists()) {
		QDir(path1).mkdir(path1);
	}
	path1+="/recent";
	string path = path1.toStdString();
	ofstream writer;
	writer.open(path.c_str());
	writer << "";
	for (int i = 0; i<recentItems->size(); i++) {
		writer << recentItems->at(i).toStdString() << endl;
	}
	writer.close();
}
