//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "settings_dialog.hpp"
#include "editor_page.hpp"

SettingsDialog::SettingsDialog() {
    this->setWindowTitle("Settings");
    this->resize(400,300);

    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    tabs = new QTabWidget;
    layout->addWidget(tabs);

    EditorPage *page1 = new EditorPage;
    tabs->addTab(page1,"Editor Settings");

    buttons = new QDialogButtonBox;
    buttons->addButton(QDialogButtonBox::Ok);
    layout->addWidget(buttons);

    connect(buttons,&QDialogButtonBox::accepted,this,&SettingsDialog::close);
}

SettingsDialog::~SettingsDialog() {
    delete layout;
    delete tabs;
    delete buttons;
}
