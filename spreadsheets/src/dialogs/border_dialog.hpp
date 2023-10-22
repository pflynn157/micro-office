//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDialog>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QDialogButtonBox>

class BorderDialog : public QDialog {
    Q_OBJECT
public:
    BorderDialog();
    ~BorderDialog();
private:
    QString color = "";
    QString width = "1";
    QString type = "solid";
    QFrame *mainWidget, *colorWidget, *widthWidget, *typeWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *colorLayout, *widthLayout, *typeLayout;
    QPushButton *chooseColor;
    QSpinBox *widthSpinner;
    QComboBox *borderTypes;
    QDialogButtonBox *dialogButtons;
private slots:
    void onColorChanged();
    void onWidthChanged();
    void onTypeChanged();
    void onClose();
};
