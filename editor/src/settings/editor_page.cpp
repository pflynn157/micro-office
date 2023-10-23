//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QVariant>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QSettings>

#include <tabpane.hpp>
#include <editor.hpp>
#include <global.hpp>
#include <settings/editor_page.hpp>

EditorPage::EditorPage() {
    layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    subLayout = new QVBoxLayout;
    subLayout->setContentsMargins(0,0,0,0);
    subWidget = new QFrame;
    subWidget->setLayout(subLayout);
    layout->addWidget(subWidget,0,Qt::AlignTop);

    //Font settings
    QFrame *fontWidget = new QFrame;
    QHBoxLayout *fontLayout = new QHBoxLayout;
    fontWidget->setLayout(fontLayout);
    subLayout->addWidget(fontWidget);

    QLabel *fontLabel = new QLabel("Choose font for current page: ");
    fontLayout->addWidget(fontLabel);

    QPushButton *chooseFontButton = new QPushButton("Choose");
    connect(chooseFontButton,&QPushButton::clicked,this,&EditorPage::onChooseFontClicked);
    fontLayout->addWidget(chooseFontButton);

    //Line highlighter color settings
    QFrame *lineColorWidget = new QFrame;
    QHBoxLayout *lineColorLayout = new QHBoxLayout;
    lineColorWidget->setLayout(lineColorLayout);
    subLayout->addWidget(lineColorWidget);

    QLabel *lineColorLabel = new QLabel("Choose color for current line highlighter: ");
    lineColorLayout->addWidget(lineColorLabel);

    currentColor = new QLineEdit;
    currentColor->setReadOnly(true);
    currentColor->setStyleSheet("background-color: "+settings.value("editor/line_color","#d9d9d9").toString()+";");
    currentColor->setFixedWidth(50);
    lineColorLayout->addWidget(currentColor);

    QPushButton *lineColorButton = new QPushButton("Choose");
    connect(lineColorButton,&QPushButton::clicked,this,&EditorPage::onChooseLineHighlighterClicked);
    lineColorLayout->addWidget(lineColorButton);

    //Autoindent settings
    QFrame *aiWidget = new QFrame;
    QHBoxLayout *aiLayout = new QHBoxLayout;
    aiWidget->setLayout(aiLayout);
    subLayout->addWidget(aiWidget);

    QCheckBox *aiCheckBox = new QCheckBox("Auto indent");
    aiCheckBox->setChecked(settings.value("editor/autoindent","true").toBool());
    connect(aiCheckBox,SIGNAL(clicked(bool)),this,SLOT(onAutoIndentClicked(bool)));
    aiLayout->addWidget(aiCheckBox);
}

EditorPage::~EditorPage() {
    delete layout;
    delete subLayout;
    delete subWidget;
}

void EditorPage::onChooseFontClicked() {
    QFontDialog dialog;
    dialog.setCurrentFont(TabPane::currentWidget()->font());
    if (dialog.exec()) {
        QFont font = dialog.selectedFont();
        settings.setValue("editor/font", font.family());
        settings.setValue("editor/font_size", font.pointSize());
        TabPane::currentWidget()->updateFont();
    }
}

void EditorPage::onChooseLineHighlighterClicked() {
    QColor color = QColorDialog::getColor(QColor("#d9d9d9"));
    currentColor->setStyleSheet("background-color: "+color.name()+";");
    settings.setValue("editor/line_color",color.name());
    Editor::updateSettings();
}

void EditorPage::onAutoIndentClicked(bool ai) {
    if (ai) {
        settings.setValue("editor/autoindent","true");
        Window::intelIndent->show();
    } else {
        settings.setValue("editor/autoindent","false");
        Window::intelIndent->hide();
    }
    Editor::updateSettings();
}

