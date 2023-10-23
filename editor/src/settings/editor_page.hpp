//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QLineEdit>

class EditorPage : public QFrame {
    Q_OBJECT
public:
    EditorPage();
    ~EditorPage();
private:
    QVBoxLayout *layout, *subLayout;
    QFrame *subWidget;
    QLineEdit *currentColor;
private slots:
    void onChooseFontClicked();
    void onChooseLineHighlighterClicked();
    void onAutoIndentClicked(bool ai);
};
