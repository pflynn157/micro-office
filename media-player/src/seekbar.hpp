//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QSlider>
#include <QLabel>

class SeekBar : public QToolBar {
    Q_OBJECT
public:
    SeekBar();
    ~SeekBar();
    static void setDuration(qint64 len);
    static void setPosition(qint64 pos);
private:
    static QString timeStr(qint64 pos);
    static QSlider *seeker;
    static QLabel *posLabel, *timeLabel;
private slots:
    void onSliderMoved(int pos);
};
