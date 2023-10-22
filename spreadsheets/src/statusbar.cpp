//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "statusbar.hpp"

StatusBar::StatusBar()
    : pathLabel(new QLabel),
      savedLabel(new QLabel)
{
    pathLabel->setText("untitled");
    savedLabel->setText("Saved");

    this->addWidget(pathLabel);
    this->addPermanentWidget(savedLabel);
}

StatusBar::~StatusBar() {
    delete pathLabel;
    delete savedLabel;
}

void StatusBar::setPathLabel(QString label) {
    pathLabel->setText(label);
}

void StatusBar::setSavedLabel(bool saved) {
    if (saved) {
        savedLabel->setText("Saved");
    } else {
        savedLabel->setText("Not saved");
    }
}
