//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "keyboardshortcutsdialog.hpp"
#include "ui_keyboardshortcutsdialog.h"

KeyboardShortcutsDialog::KeyboardShortcutsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyboardShortcutsDialog)
{
    ui->setupUi(this);
}

KeyboardShortcutsDialog::~KeyboardShortcutsDialog() {
    delete ui;
}

void KeyboardShortcutsDialog::on_closeButton_clicked() {
    this->close();
}
