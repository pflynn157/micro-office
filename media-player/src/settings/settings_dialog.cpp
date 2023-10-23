//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QVariant>

#include "settings_dialog.hpp"
#include "ui_settings_dialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::SettingsDialog) {
    ui->setupUi(this);

    //int volumeValue = QVariant(Settings::getSetting("volume","10")).toInt();
    //bool showTaskbar = QVariant(Settings::getSetting("taskbar/icon","true")).toBool();
    int volumeValue = 10;
    bool showTaskbar = true;

    ui->volumeSpinner->setValue(volumeValue);
    ui->taskbarIcon->setChecked(showTaskbar);
}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

void SettingsDialog::on_saveButton_clicked() {
    int volumeValue = ui->volumeSpinner->value();
    bool showTaskbar = ui->taskbarIcon->isChecked();

    //Settings::writeSetting("volume",QVariant(volumeValue).toString());
    //Settings::writeSetting("taskbar/icon",QVariant(showTaskbar).toString());

    this->close();
}

void SettingsDialog::on_cancelButton_clicked() {
    this->close();
}
