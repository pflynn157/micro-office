//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QInputDialog>
#include <QMenu>
#include <QAction>
#include <QCursor>

#include "project_tree.hpp"
#include "../window.hpp"

ProjectTree::ProjectTree() {
    this->setHeaderLabel("Project");
    
    connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
    connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(onItemExpanded(QTreeWidgetItem*)));
    connect(this, SIGNAL(itemCollapsed(QTreeWidgetItem*)), this, SLOT(onItemCollapsed(QTreeWidgetItem*)));
}

void ProjectTree::setFilePath(QString path) {
    filePath = path;
    if (!filePath.endsWith("/")) {
        filePath+="/";
    }
    
    loadTreeData(filePath);
}

QString ProjectTree::getFilePath() {
    return filePath;
}

QString ProjectTree::getSelectedPath() {

    auto items = this->selectedItems();
    
    if (items.size() == 0) {
        return filePath;
    }
    
    QTreeWidgetItem *item = items[0];
    QTreeWidgetItem *parent = item->parent();
    QString path = "";
    
    while (parent != nullptr) {
        path = parent->text(0) + "/" + path;
        parent = parent->parent();
    }
    path += item->text(0);
    path = filePath + path;
    
    return path;
}

void ProjectTree::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction *rename = new QAction("Rename", this);
        connect(rename, &QAction::triggered, this, &ProjectTree::onRenameClicked);
    
        menu.addAction(rename);
        menu.exec(QCursor::pos());
    } else {
        QTreeWidget::mousePressEvent(event);
    }
}

void ProjectTree::loadTreeData(QString path) {
    this->clear();
    
    auto toExpand = loadTree(path, nullptr);
    for (auto current : toExpand) {
        QString path = getItemPath(current, 0);
        for (QString currentPath : expandedPaths) {
            if (currentPath == path) {
                current->setExpanded(true);
                break;
            }
        }
    }
}

QList<QTreeWidgetItem *> ProjectTree::loadTree(QString path, QTreeWidgetItem *parent, int layer) {
    QStringList entries = QDir(path).entryList();
    QList<QTreeWidgetItem *> items;
    QList<QTreeWidgetItem *> toExpand;
    
    // Holds file and folder items so that they are properly sorted when loaded
    QList<QTreeWidgetItem *> folderList;
    QList<QTreeWidgetItem *> fileList;
    
    if (!path.endsWith("/")) {
        path+="/";
    }
    
    for (int i = 0; i<entries.size(); i++) {
        if ((entries.at(i)==".")||(entries.at(i)=="..")) {
            continue;
        }
        
        // TODO: Maybe we want to add some kind of setting for this?
        if (entries.at(i).endsWith(".o") || entries.at(i).endsWith(".d")
            || entries.at(i).endsWith(".elf") || entries.at(i).endsWith(".bin")) {
            continue;
        }
        
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0,QFileInfo(entries.at(i)).fileName());
        
        QString itemPath = path + entries.at(i);
        
        if (QFileInfo(itemPath).isDir()) {
            item->setIcon(0,QIcon::fromTheme("inode-directory",QPixmap(":/icons/inode-directory.png")));
            if (layer < 10) {
                toExpand.append(loadTree(itemPath,item, layer + 1));
            }
            
            if (expandedPaths.contains(itemPath)) {
                toExpand.append(item);
            }
            
            folderList.push_back(item);
        } else {
            item->setIcon(0,QIcon::fromTheme("text-x-generic",QPixmap(":/icons/text-x-generic.png")));
            fileList.push_back(item);
        }
    }
    
    // Now, add
    for (QTreeWidgetItem *item : folderList) {
        if (parent == nullptr) items.push_back(item);
        else parent->addChild(item);
    }
    
    for (QTreeWidgetItem *item : fileList) {
        if (parent == nullptr) items.push_back(item);
        else parent->addChild(item);
    }
    
    this->insertTopLevelItems(0,items);
    
    return toExpand;
}

QString ProjectTree::getItemPath(QTreeWidgetItem *item, int col) {
    QTreeWidgetItem *parent = item->parent();
    QString path = "";
    
    while (parent != nullptr) {
        path = parent->text(col) + "/" + path;
        parent = parent->parent();
    }
    path += item->text(col);
    path = filePath + path;
    
    return path;
}

QString ProjectTree::currentSelected() {
    auto items = this->selectedItems();
    if (items.size() == 0)
        return "";
    
    int col = this->currentColumn();
    QTreeWidgetItem *item = items.at(0);
    
    return getItemPath(item, col);
}

void ProjectTree::onItemDoubleClicked(QTreeWidgetItem *item, int col) {
    QString path = getItemPath(item, col);

    if (QFileInfo(path).isDir()) {
        setFilePath(path);
    } else {
        Window::addFile(path);
    }
}

void ProjectTree::onItemExpanded(QTreeWidgetItem *item) {
    QString path = getItemPath(item, 0);
    expandedPaths.append(path);
}

void ProjectTree::onItemCollapsed(QTreeWidgetItem *item) {
    QString path = getItemPath(item, 0);
    expandedPaths.removeAll(path);
}

void ProjectTree::onRenameClicked() {
    QString path = currentSelected();
    if (path == "")
        return;
        
    QString name = QInputDialog::getText(nullptr, "Rename File", "Enter file name:");
    QString newPath = QFileInfo(path).absolutePath() + "/" + name;
    
    if (QFileInfo(path).isDir()) {
        QDir().rename(path, newPath);
    } else {
        QFile::rename(path, newPath);
    }
    
    loadTreeData(filePath);
}

