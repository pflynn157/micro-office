//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDialog>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDialogButtonBox>

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    SettingsDialog();
    ~SettingsDialog();
private:
    QVBoxLayout *layout;
    QTabWidget *tabs;
    QDialogButtonBox *buttons;
};
