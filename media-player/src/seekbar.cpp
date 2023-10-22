//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QToolBar>
#include <QSlider>
#include <QLabel>

#include "seekbar.hpp"
#include "videopane.hpp"

QLabel *SeekBar::posLabel;
QSlider *SeekBar::seeker;
QLabel *SeekBar::timeLabel;

SeekBar::SeekBar() {
    posLabel = new QLabel(/*"0:00"*/);
    seeker = new QSlider(Qt::Horizontal);
    timeLabel = new QLabel();

    seeker->setMinimum(0);
    seeker->setMaximum(0);

    connect(seeker,SIGNAL(sliderMoved(int)),this,SLOT(onSliderMoved(int)));

    this->addWidget(posLabel);
    this->addWidget(seeker);
    this->addWidget(timeLabel);
}

SeekBar::~SeekBar() {
    delete posLabel;
    delete seeker;
    delete timeLabel;
}

void SeekBar::setDuration(qint64 len) {
    seeker->setMinimum(0);
    seeker->setMaximum(len);
    timeLabel->setText(timeStr(len));
}

void SeekBar::setPosition(qint64 pos) {
    seeker->setValue(pos);
    posLabel->setText(timeStr(pos));
}

QString SeekBar::timeStr(qint64 pos) {
    qint64 seconds = (pos/1000);
    qint64 min = (seconds/60);
    qint64 re_sec = (seconds-(min*60));

    QString secondNumber = QString::number(re_sec);
    if (re_sec<10) {
        secondNumber="0"+secondNumber;
    }
    QString timeStr = QString::number(min)+":"+secondNumber;
    return timeStr;
}

void SeekBar::onSliderMoved(int pos) {
    VideoPane::player->setPosition(pos);
}
