//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QMainWindow>
#include <QToolButton>
#include <QSpinBox>
#include <QComboBox>

class MainToolBar : public QToolBar {
    Q_OBJECT
public:
    explicit MainToolBar(QMainWindow *parentWindow);
    ~MainToolBar();
    void setFontSize(int val);
    void setSyntaxName(QString name);
private:
    QMainWindow *parent;
    QToolButton *newFile, *openFile, *saveFile, *saveFileAs;
    QToolButton *cut, *copy, *paste, *undo, *redo;
    QSpinBox *fontSize;
    QComboBox *syntaxmenu;
private slots:
    void onFontSizeChanged();
    void onComboTextChanged(QString item);
};

