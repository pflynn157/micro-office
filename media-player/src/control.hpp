//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>
#include <QSlider>

#include "seekbar.hpp"

class ControlBar : public QToolBar {
    Q_OBJECT
public:
    ControlBar();
    ~ControlBar();
private:
    QToolButton *open, *play, *pause, *stop, *back, *next;
    SeekBar *seekbar;
    QToolButton *volume;
    QSlider *volumeSlider;
private slots:
    void onOpenClicked();
    void onPlayClicked();
    void onPauseClicked();
    void onStopClicked();
    void onBackClicked();
    void onNextClicked();
    void onVolumeSliderClicked(int val);
};
