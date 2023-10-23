//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QPushButton>
#include <QDate>

#include "subwindow.hpp"

class DateDockWidget : public SubWindow {
    Q_OBJECT
public:
    DateDockWidget();
private:
    QFrame *mainWidget, *bottomWidget;
    QVBoxLayout *mainLayout;
    QCalendarWidget *calendar;
    QHBoxLayout *bottomLayout;
    QDateEdit *dateDisplay;
    QPushButton *submit;
private slots:
    void onDateClicked(QDate date);
    void onSubmitClicked();
};
