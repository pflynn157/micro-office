//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMouseEvent>

class VideoPane : public QVideoWidget {
    Q_OBJECT
public:
    VideoPane();
    static QMediaPlayer *player;
    //static QMediaPlaylist *playlist;
    static void addMedia(QString path);
    //static void setAndRunPlaylist(QMediaPlaylist *playlist);
    static void startPlaying();
protected:
    QAudioOutput *audio;
	void mousePressEvent(QMouseEvent *event);
private slots:
    void onPlayerChanged(qint64 pos);
    void onDurationChanged(qint64 pos);
    void onErrorOccurred(QMediaPlayer::Error error, QString errorString);
};
