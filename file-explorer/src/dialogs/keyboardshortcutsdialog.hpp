//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDialog>

namespace Ui {
class KeyboardShortcutsDialog;
}

class KeyboardShortcutsDialog : public QDialog {
    Q_OBJECT
public:
    explicit KeyboardShortcutsDialog(QWidget *parent = 0);
    ~KeyboardShortcutsDialog();
private slots:
    void on_closeButton_clicked();
private:
    Ui::KeyboardShortcutsDialog *ui;
};
