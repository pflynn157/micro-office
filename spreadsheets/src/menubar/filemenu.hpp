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
private:
    QAction *newFile, *open, *save, *saveAs, *quit;
private slots:
    void onNewFileClicked();
    void onOpenClicked();
    void onSaveClicked();
    void onSaveAsClicked();
    void onQuitClicked();
};
