//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>
#include <QFontComboBox>
#include <QSpinBox>

class MainToolbar : public QToolBar {
    Q_OBJECT
public:
    MainToolbar();
    ~MainToolbar();
private:
    QToolButton *newFile, *open, *save, *saveAs;
    QToolButton *bold, *italic, *underline;
    QFontComboBox *fontCombo;
    QSpinBox *fontSize;
    QToolButton *cut, *copy, *paste;
private slots:
    void onNewFileClicked();
    void onOpenClicked();
    void onSaveClicked();
    void onSaveAsClicked();
    void onBoldClicked();
    void onItalicClicked();
    void onUnderlineClicked();
    void onFontChanged(QFont font);
    void onFontSizeChanged(int val);
    void onCutClicked();
    void onCopyClicked();
    void onPasteClicked();
};
