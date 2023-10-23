//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMenu>
#include <QAction>
#include <QUrl>
#include <QVariant>
#include <iostream>

#include "videopane.hpp"
#include "seekbar.hpp"
#include "videopane_menu.hpp"

QMediaPlayer *VideoPane::player;
//QMediaPlaylist *VideoPane::playlist;

VideoPane::VideoPane() {
    player = new QMediaPlayer;
    audio = new QAudioOutput;
    player->setAudioOutput(audio);
    audio->setVolume(10);
    player->setVideoOutput(this);
    player->setPosition(0);   

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(onPlayerChanged(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));
    connect(player,SIGNAL(errorOccurred(QMediaPlayer::Error, QString)), this, SLOT(onErrorOccurred(QMediaPlayer::Error, QString)));
}

void VideoPane::addMedia(QString path) {
	player->setSource(QUrl::fromLocalFile(path));
}

/*void VideoPane::setAndRunPlaylist(QMediaPlaylist *playlist) {
	player->setPlaylist(playlist);
	player->play();
}*/

void VideoPane::startPlaying() {
    player->play();
}

void VideoPane::onPlayerChanged(qint64 pos) {
    SeekBar::setPosition(pos);
}

void VideoPane::onDurationChanged(qint64 pos) {
    SeekBar::setDuration(pos);
}

void VideoPane::onErrorOccurred(QMediaPlayer::Error error, QString errorString) {
    std::cout << "[ERROR] " << errorString.toStdString() << std::endl;
}

void VideoPane::mousePressEvent(QMouseEvent *event) {
	if (event->button()==Qt::RightButton) {
		VideoPaneMenu().exec(QCursor::pos());
	}
}
