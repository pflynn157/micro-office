//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class FileMenu : public QMenu {
    Q_OBJECT
public:
    FileMenu();
    ~FileMenu();
    static void refreshRecentEntries();
private:
    QAction *open, *quit;
    static QMenu *recent;
private slots:
	void onOpenClicked();
};
