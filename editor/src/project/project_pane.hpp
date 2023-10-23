//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QMouseEvent>

#include "project_tree.hpp"

class ProjectPane : public QFrame {
    Q_OBJECT
public:
    ProjectPane();
    ~ProjectPane();
    void loadTree();
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QVBoxLayout *layout;
    QToolBar *toolbar;
    QToolButton *goUp, *newFile, *newFolder, *refresh;
    ProjectTree *projectTree;
private slots:
    void onGoUpClicked();
    void onNewFileClicked();
    void onNewFolderClicked();
    void onRefreshClicked();
};
