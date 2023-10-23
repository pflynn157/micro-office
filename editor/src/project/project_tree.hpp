//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMouseEvent>
#include <QStringList>
#include <QList>

class ProjectTree : public QTreeWidget {
    Q_OBJECT
public:
    ProjectTree();
    void setFilePath(QString path);
    QString getFilePath();
    QString getSelectedPath();
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    void loadTreeData(QString path);
    QList<QTreeWidgetItem *> loadTree(QString path, QTreeWidgetItem *parent, int layer = 0);
    QString getItemPath(QTreeWidgetItem *item, int col);
    QString currentSelected();
    QString filePath;
    QStringList expandedPaths;
private slots:
    void onItemDoubleClicked(QTreeWidgetItem *item, int col);
    void onItemExpanded(QTreeWidgetItem *item);
    void onItemCollapsed(QTreeWidgetItem *item);
    void onRenameClicked();
};
