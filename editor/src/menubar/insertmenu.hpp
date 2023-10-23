//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMenu>
#include <QMainWindow>
#include <QAction>
#include <QChar>
#include <QDialog>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDialogButtonBox>

class LoremIpsumDialog;

class InsertMenu : public QMenu {
    Q_OBJECT
public:
    explicit InsertMenu(QMainWindow *parent);
    ~InsertMenu();
private:
    QMainWindow *window;
    QAction *datePicker, *loremIpsum, *colorDialog;
private slots:
    void onDatePickerClicked();
    void onLoremIpsumClicked();
    void onColorDialogClicked();
};

class LoremIpsumDialog : public QDialog {
    Q_OBJECT
public:
    LoremIpsumDialog();
    ~LoremIpsumDialog();
private:
    QFrame *centerWidget;
    QVBoxLayout *centerLayout;
    QLabel *label;
    QTextEdit *edit;
    QDialogButtonBox *buttons;
private slots:
    void onOkClicked();
    void onCancelClicked();
};
