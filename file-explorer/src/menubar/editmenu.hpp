//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QAction>

class EditMenu : public QMenu{
public:
    EditMenu();
    ~EditMenu();
private:
    QAction *selectAll;
    QAction *cut, *copy, *paste;
    QAction *trash, *deleteFile;
private slots:
    void onSelectAllClicked();
    void onCutClicked();
    void onCopyClicked();
    void onPasteClicked();
    void onTrashClicked();
    void onDeleteFileClicked();
};
