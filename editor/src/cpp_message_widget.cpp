//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QPropertyAnimation>

#include "cpp_message_widget.hpp"
#include "global/file_actions.hpp"

CppMessageWidget::CppMessageWidget() : CppMessageWidget("") { }

CppMessageWidget::CppMessageWidget(QString text) {
    layout = new QHBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    label = new QLabel(text);
    layout->addWidget(label,0,Qt::AlignLeft);

    close = new QToolButton;
    close->setText("X");
    connect(close,&QToolButton::clicked,this,&CppMessageWidget::onCloseClicked);
    layout->addWidget(close,0,Qt::AlignRight);

    this->setStyleSheet(FileActions::fileContents(":/rsc/message_widget.css"));

    h = this->height();
}

CppMessageWidget::~CppMessageWidget() {
    delete layout;
    delete label;
    delete close;
}

void CppMessageWidget::animatedShow() {
    this->show();
    QPropertyAnimation *animation = new QPropertyAnimation(this,"maximumHeight");
    animation->setDuration(2000);
    animation->setStartValue(0);
    animation->setEndValue(h);
    animation->start();
}

void CppMessageWidget::setCloseButtonVisible(bool show) {
    if (show) {
        close->show();
    } else {
        close->hide();
    }
}

void CppMessageWidget::setText(QString text) {
    label->setText(text);
}

void CppMessageWidget::onCloseClicked() {
    this->hide();
}
