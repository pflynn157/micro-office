//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QIcon>
#include <QDir>

#include "navbar.hpp"

NavBar::NavBar()
    : goBack(new QToolButton),
      goUp(new QToolButton),
      refresh(new QToolButton),
      home(new QToolButton)
{
    this->setMovable(false);
    this->setContextMenuPolicy(Qt::PreventContextMenu);

    goBack->setIcon(QIcon::fromTheme("go-previous",QPixmap(":/icons/go-previous.svg")));
    goUp->setIcon(QIcon::fromTheme("go-up",QPixmap(":/icons/go-up.svg")));
    refresh->setIcon(QIcon::fromTheme("view-refresh",QPixmap(":/icons/view-refresh.svg")));
    home->setIcon(QIcon::fromTheme("go-home",QPixmap(":/icons/user-home.svg")));

    goBack->setEnabled(false);
    goUp->setEnabled(false);

    connect(goBack,&QToolButton::clicked,this,&NavBar::onGoBackClicked);
    connect(goUp,&QToolButton::clicked,this,&NavBar::onGoUpClicked);
    connect(refresh,&QToolButton::clicked,this,&NavBar::onRefreshClicked);
    connect(home,&QToolButton::clicked,this,&NavBar::onHomeClicked);

    this->addWidget(goBack);
    this->addWidget(goUp);
    this->addWidget(refresh);
    this->addWidget(home);
}

NavBar::~NavBar() {
    delete goBack;
    delete goUp;
    delete refresh;
    delete home;
}

void NavBar::setBrowserWidget(BrowserWidget *b) {
    bWidget = b;
    if (bWidget->fsCurrentPath()=="/") {
        goUp->setEnabled(false);
    } else {
        goUp->setEnabled(true);
    }
    if (b->history().isEmpty()) {
        goBack->setEnabled(false);
    } else {
        goBack->setEnabled(true);
    }
    connect(bWidget,SIGNAL(dirChanged(QString)),this,SLOT(onDirChanged(QString)));
    connect(bWidget,&BrowserWidget::historyChanged,this,&NavBar::onHistoryChanged);
}

void NavBar::onGoUpClicked() {
    if (bWidget==nullptr) {
        return;
    }
    QString currentPath = bWidget->fsCurrentPath();
    QDir dir(currentPath);
    dir.cdUp();
    QString newPath = dir.path();
    bWidget->loadDir(newPath);
}

void NavBar::onGoBackClicked() {
    QString path = bWidget->history().first();
    bWidget->loadDir(path);
}

void NavBar::onRefreshClicked() {
    bWidget->reload();
}

void NavBar::onHomeClicked() {
    bWidget->loadDir();
}

void NavBar::onDirChanged(QString path) {
    if (path=="/") {
        goUp->setEnabled(false);
    } else {
        goUp->setEnabled(true);
    }
}

void NavBar::onHistoryChanged() {
    if (bWidget->history().isEmpty()) {
        goBack->setEnabled(false);
    } else {
        goBack->setEnabled(true);
    }
}
