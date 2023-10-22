//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QToolBar>
#include <QToolButton>
#include <QPixmap>
#include <QVariant>
#include <QWidgetAction>
#include <QMenu>

#include "control.hpp"
#include "actions.hpp"
#include "videopane.hpp"
#include "seekbar.hpp"

ControlBar::ControlBar() {
    open = new QToolButton;
    play = new QToolButton;
    pause = new QToolButton;
    stop = new QToolButton;
    back = new QToolButton;
    next = new QToolButton;
    seekbar = new SeekBar;
    volume = new QToolButton;

    volume->setPopupMode(QToolButton::InstantPopup);
    QMenu *menu = new QMenu();
    volume->setMenu(menu);

    volumeSlider = new QSlider;
    volumeSlider->setMinimum(0);
    volumeSlider->setMaximum(100);
    //volumeSlider->setValue(VideoPane::player->volume());
    connect(volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(onVolumeSliderClicked(int)));

    QWidgetAction *va = new QWidgetAction(menu);
    va->setDefaultWidget(volumeSlider);
    menu->addAction(va);

    QPixmap documentOpenIcon(":/icons/document-open.svg");
    QPixmap playIcon(":/icons/media-playback-start.svg");
    QPixmap pauseIcon(":/icons/media-playback-pause.svg");
    QPixmap stopIcon(":/icons/media-playback-stop.svg");
    QPixmap backIcon(":/icons/media-seek-backward.svg");
    QPixmap nextIcon(":/icons/media-seek-forward.svg");
    QPixmap volumeIcon(":/icons/audio-volume-high.svg");

    open->setIcon(QIcon::fromTheme("document-open",documentOpenIcon));
    play->setIcon(QIcon::fromTheme("media-playback-start",playIcon));
    pause->setIcon(QIcon::fromTheme("media-playback-pause",pauseIcon));
    stop->setIcon(QIcon::fromTheme("media-playback-stop",stopIcon));
    back->setIcon(QIcon::fromTheme("media-seek-backward",backIcon));
    next->setIcon(QIcon::fromTheme("media-seek-forward",nextIcon));
    volume->setIcon(QIcon::fromTheme("audio-volume-high",volumeIcon));

    connect(open,&QToolButton::clicked,this,&ControlBar::onOpenClicked);
    connect(play,&QToolButton::clicked,this,&ControlBar::onPlayClicked);
    connect(pause,&QToolButton::clicked,this,&ControlBar::onPauseClicked);
    connect(stop,&QToolButton::clicked,this,&ControlBar::onStopClicked);
    connect(back,&QToolButton::clicked,this,&ControlBar::onBackClicked);
    connect(next,&QToolButton::clicked,this,&ControlBar::onNextClicked);

    this->addWidget(open);
    this->addWidget(play);
    this->addWidget(pause);
    this->addWidget(stop);
    this->addWidget(back);
    this->addWidget(next);
    this->addWidget(seekbar);
    this->addWidget(volume);
}

ControlBar::~ControlBar() {
    delete open;
    delete play;
    delete pause;
    delete stop;
    delete back;
    delete next;
    delete volume;
}

void ControlBar::onOpenClicked() {
    Actions::open();
}

void ControlBar::onPlayClicked() {
    VideoPane::player->play();
}

void ControlBar::onPauseClicked() {
    VideoPane::player->pause();
}

void ControlBar::onStopClicked() {
    VideoPane::player->stop();
}

void ControlBar::onBackClicked() {
    Actions::seekBack();
}

void ControlBar::onNextClicked() {
    Actions::seekForward();
}

void ControlBar::onVolumeSliderClicked(int val) {
    //VideoPane::player->setVolume(val);
}
