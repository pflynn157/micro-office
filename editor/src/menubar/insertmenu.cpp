//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QColorDialog>

#include "insertmenu.hpp"
#include "../window.hpp"
#include "../global/file_actions.hpp"
#include "../tabpane.hpp"
#include "../editor.hpp"

InsertMenu::InsertMenu(QMainWindow *parent) {
    window = parent;
    this->setTitle("Insert");

    datePicker = new QAction("Insert a date",this);
    loremIpsum = new QAction("Insert Lorem Ipsum text",this);
    colorDialog = new QAction("Insert a color",this);

    connect(datePicker,&QAction::triggered,this,&InsertMenu::onDatePickerClicked);
    connect(loremIpsum,&QAction::triggered,this,&InsertMenu::onLoremIpsumClicked);
    connect(colorDialog,&QAction::triggered,this,&InsertMenu::onColorDialogClicked);

    this->addAction(datePicker);
    this->addAction(loremIpsum);
    this->addAction(colorDialog);
}

InsertMenu::~InsertMenu() {
    delete datePicker;
    delete loremIpsum;
    delete colorDialog;
}

void InsertMenu::onDatePickerClicked() {
    Window::dispalyDateSelector();
}

void InsertMenu::onLoremIpsumClicked() {
    LoremIpsumDialog dialog;
    dialog.exec();
}

void InsertMenu::onColorDialogClicked() {
    QColorDialog dialog;
    if (dialog.exec()) {
        QColor color = dialog.selectedColor();
        TextEdit *edit = TabPane::currentEditor();
        edit->insertPlainText(color.name());
    }
}

//The LoremIpsum dialog
LoremIpsumDialog::LoremIpsumDialog()
    : centerWidget(new QFrame),
      centerLayout(new QVBoxLayout),
      label(new QLabel),
      edit(new QTextEdit),
      buttons(new QDialogButtonBox)
{
    this->setWindowTitle("Insert Lorem Ipsum Text");
    this->resize(500,400);
    this->setLayout(centerLayout);

    label->setText("Choose the text to be inserted:");

    QString text = FileActions::fileContents(":/rsc/lorem_ipsum.txt");
    edit->setText(text);

    buttons->addButton(QDialogButtonBox::Cancel);
    buttons->addButton(QDialogButtonBox::Ok);

    connect(buttons,&QDialogButtonBox::accepted,this,&LoremIpsumDialog::onOkClicked);
    connect(buttons,&QDialogButtonBox::rejected,this,&LoremIpsumDialog::onCancelClicked);

    centerLayout->addWidget(label,0,Qt::AlignTop);
    centerLayout->addWidget(edit);
    centerLayout->addWidget(buttons);
}

LoremIpsumDialog::~LoremIpsumDialog() {
    delete centerWidget;
    delete centerLayout;
    delete label;
    delete edit;
    delete buttons;
}

void LoremIpsumDialog::onOkClicked() {
    QString text = edit->toPlainText();
    TextEdit *editor = TabPane::currentEditor();
    editor->insertPlainText(text);
    this->close();
}

void LoremIpsumDialog::onCancelClicked() {
    this->close();
}
