//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "date_selector.hpp"
#include "../tabpane.hpp"

DateDockWidget::DateDockWidget() {
    this->setWindowTitle("Date Picker");

    mainWidget = new QFrame;
    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0,0,0,0);
    mainWidget->setLayout(mainLayout);
    this->setWidget(mainWidget);

    calendar = new QCalendarWidget;
    mainLayout->addWidget(calendar);

    bottomWidget = new QFrame;
    bottomLayout = new QHBoxLayout;
    bottomLayout->setContentsMargins(0,0,0,0);
    bottomWidget->setLayout(bottomLayout);
    mainLayout->addWidget(bottomWidget);

    dateDisplay = new QDateEdit;
    dateDisplay->setDate(calendar->selectedDate());
    bottomLayout->addWidget(dateDisplay);

    submit = new QPushButton("Add");
    bottomLayout->addWidget(submit);

    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(onDateClicked(QDate)));
    connect(submit,&QPushButton::clicked,this,&DateDockWidget::onSubmitClicked);
}

void DateDockWidget::onDateClicked(QDate date) {
    dateDisplay->setDate(date);
}

void DateDockWidget::onSubmitClicked() {
    QDate date = dateDisplay->date();
    QString date_str = date.toString();
    TabPane::currentEditor()->insertPlainText(date_str);
}

