//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>

class CppMessageWidget : public QFrame {
    Q_OBJECT
public:
    explicit CppMessageWidget();
    explicit CppMessageWidget(QString text);
    ~CppMessageWidget();
    void animatedShow();
    void setCloseButtonVisible(bool show);
    void setText(QString text);
private:
    QHBoxLayout *layout;
    QLabel *label;
    QToolButton *close;
    int h = 100;
private slots:
    void onCloseClicked();
};
