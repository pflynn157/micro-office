//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QColorDialog>

#include "border_dialog.hpp"
#include "../tabwidget.hpp"

BorderDialog::BorderDialog()
    : colorWidget(new QFrame),
      widthWidget(new QFrame),
      typeWidget(new QFrame),
      mainLayout(new QVBoxLayout),
      colorLayout(new QHBoxLayout),
      widthLayout(new QHBoxLayout),
      typeLayout(new QHBoxLayout),
      borderTypes(new QComboBox)
{
    this->setWindowTitle("Set Cell Border");
    this->setFixedSize(300,200);

    mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(mainLayout);

    //===The border color controls===
    colorWidget->setLayout(colorLayout);

    chooseColor = new QPushButton("Choose Color");
    connect(chooseColor,&QPushButton::clicked,this,&BorderDialog::onColorChanged);

    colorLayout->addWidget(new QLabel("Choose color: "));
    colorLayout->addWidget(chooseColor);

    mainLayout->addWidget(colorWidget);

    //===The border width controls===
    widthWidget->setLayout(widthLayout);

    widthSpinner = new QSpinBox;
    widthSpinner->setMinimum(1);
    widthSpinner->setMaximum(100);
    widthSpinner->setValue(3);
    connect(widthSpinner,SIGNAL(valueChanged(int)),this,SLOT(onWidthChanged()));

    widthLayout->addWidget(new QLabel("Set width: "));
    widthLayout->addWidget(widthSpinner);

    mainLayout->addWidget(widthWidget);

    //===The border type controls===
    typeWidget->setLayout(typeLayout);

    borderTypes->addItem("solid");
    borderTypes->addItem("dash");
    borderTypes->addItem("dot");
    borderTypes->addItem("dash_dot");
    borderTypes->addItem("dash_dot_dot");
    connect(borderTypes,&QComboBox::currentTextChanged,this,&BorderDialog::onTypeChanged);

    typeLayout->addWidget(new QLabel("Choose border type: "));
    typeLayout->addWidget(borderTypes);

    mainLayout->addWidget(typeWidget);

    //The dialog buttons
    dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(dialogButtons,&QDialogButtonBox::accepted,this,&BorderDialog::onClose);
    connect(dialogButtons,&QDialogButtonBox::rejected,this,&BorderDialog::close);

    mainLayout->addWidget(dialogButtons);
}

BorderDialog::~BorderDialog() {
    /*delete mainWidget;
    delete colorWidget;
    delete widthWidget;
    delete typeWidget;
    delete mainLayout;
    delete colorLayout;
    delete widthLayout;
    delete typeLayout;*/
}

void BorderDialog::onColorChanged() {
    QColor c = QColorDialog::getColor();
    color = c.name();
}

void BorderDialog::onWidthChanged() {
    width = QVariant(widthSpinner->value()).toString();
}

void BorderDialog::onTypeChanged() {
    type = borderTypes->currentText();
}

void BorderDialog::onClose() {
    QString border = "border:";
    border+=color+",";
    border+=width+",";
    border+=type;

    SheetWidget *current = TabWidget::currentWidget();
    if (current->currentTable()->currentSelectedItems().size()==1) {
        TabWidget::currentWidget()->currentCell()->setData(Qt::UserRole,QVariant(border));
    } else {
        auto list = current->currentTable()->currentSelectedItems();
        for (auto item : list) {
            int col = item.column();
            int row = item.row();

            QTableWidgetItem *tItem = current->currentTable()->item(row,col);
            if (tItem==nullptr) {
                tItem = new QTableWidgetItem();
                current->currentTable()->setItem(row,col,tItem);
            }
            tItem->setData(Qt::UserRole,QVariant(border));
        }
    }

    this->close();
}
