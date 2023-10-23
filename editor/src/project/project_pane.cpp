//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QFileDialog>
#include <QInputDialog>
#include <QDir>
#include <QFile>

#include "project_pane.hpp"
#include <tabpane.hpp>
#include <editor.hpp>

ProjectPane::ProjectPane() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    toolbar = new QToolBar;
    layout->addWidget(toolbar,0,Qt::AlignTop);

    projectTree = new ProjectTree;
    layout->addWidget(projectTree);

    goUp = new QToolButton;
    newFile = new QToolButton;
    newFolder = new QToolButton;
    refresh = new QToolButton;
    
    goUp->setIcon(QIcon::fromTheme("go-up"));
    newFile->setIcon(QIcon::fromTheme("document-new"));
    newFolder->setIcon(QIcon::fromTheme("folder-new"));
    refresh->setIcon(QIcon::fromTheme("view-refresh"));

    connect(goUp, &QToolButton::clicked, this, &ProjectPane::onGoUpClicked);
    connect(newFile, &QToolButton::clicked, this, &ProjectPane::onNewFileClicked);
    connect(newFolder, &QToolButton::clicked, this, &ProjectPane::onNewFolderClicked);
    connect(refresh, &QToolButton::clicked, this, &ProjectPane::onRefreshClicked);

    toolbar->addWidget(goUp);
    toolbar->addWidget(newFile);
    toolbar->addWidget(newFolder);
    toolbar->addWidget(refresh);
}

ProjectPane::~ProjectPane() {
    delete layout;
}

void ProjectPane::loadTree() {
    QString currentPath = projectTree->getFilePath();

    if (currentPath == "") {
        Editor *current = TabPane::widgetAt(0);
        if (current->isUntitled()) {
            currentPath = QDir::currentPath();
        } else {
        	    QString path = current->path();
        	    currentPath = QFileInfo(path).absolutePath();
        }
    }

    projectTree->setFilePath(currentPath);
}

void ProjectPane::mousePressEvent(QMouseEvent *event) {
}

void ProjectPane::onGoUpClicked() {
    QString currentPath = projectTree->getFilePath();
    QDir dir(currentPath);
    if (dir.cdUp()) currentPath = dir.absolutePath();
    projectTree->setFilePath(currentPath);
}

void ProjectPane::onNewFileClicked() {
    QString name = QInputDialog::getText(nullptr, "New File", "Enter file name:");
    
    QString currentPath = projectTree->getSelectedPath();
    
    if (!QFileInfo(currentPath).isDir()) {
        currentPath = projectTree->getFilePath();
    }
    
    currentPath += "/" + name;
    
    QFile file(currentPath);
    if (file.open(QFile::WriteOnly)) {
        file.close();
    }
    
    loadTree();
}

void ProjectPane::onNewFolderClicked() {
    QString name = QInputDialog::getText(nullptr, "New Folder", "Enter folder name:");

    QString currentPath = projectTree->getSelectedPath();
    
    if (!QFileInfo(currentPath).isDir()) {
        currentPath = projectTree->getFilePath();
    }
    
    currentPath += "/" + name;
    
    QDir().mkpath(currentPath);
    loadTree();
}

void ProjectPane::onRefreshClicked() {
    loadTree();
}
