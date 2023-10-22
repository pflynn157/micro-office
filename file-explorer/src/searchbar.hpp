//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "browserwidget.hpp"

class BrowserWidget;

class SearchBar : public QWidget {
    Q_OBJECT
public:
    explicit SearchBar(BrowserWidget *b);
    ~SearchBar();
private:
    BrowserWidget *bWidget;
    QHBoxLayout *layout;
    QLabel *label;
    QLineEdit *entry;
    QPushButton *close;
private slots:
    void onEnterPressed();
    void onCloseClicked();
};
