/********************************************************************************
** Form generated from reading UI file 'keyboardshortcutsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDSHORTCUTSDIALOG_H
#define UI_KEYBOARDSHORTCUTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyboardShortcutsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *closeButton;

    void setupUi(QDialog *KeyboardShortcutsDialog)
    {
        if (KeyboardShortcutsDialog->objectName().isEmpty())
            KeyboardShortcutsDialog->setObjectName(QString::fromUtf8("KeyboardShortcutsDialog"));
        KeyboardShortcutsDialog->resize(456, 376);
        verticalLayout_2 = new QVBoxLayout(KeyboardShortcutsDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(KeyboardShortcutsDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addLayout(verticalLayout);

        closeButton = new QPushButton(KeyboardShortcutsDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout_2->addWidget(closeButton);


        retranslateUi(KeyboardShortcutsDialog);

        QMetaObject::connectSlotsByName(KeyboardShortcutsDialog);
    } // setupUi

    void retranslateUi(QDialog *KeyboardShortcutsDialog)
    {
        KeyboardShortcutsDialog->setWindowTitle(QCoreApplication::translate("KeyboardShortcutsDialog", "Keyboard Shortcuts", nullptr));
        textEdit->setHtml(QCoreApplication::translate("KeyboardShortcutsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-Q: Exit Program</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-T: New Tab</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-N: New file</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-X: Cut</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-C: Copy</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-V: Paste</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-A: Select All</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-R: Reload</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\""
                        ">Ctrl-H: Show/hide hidden items</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-S: Show search bar*</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Delete: Move to trash</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-Shift-N: New file</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">Ctrl-Shift-T: Close current tab</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans';\">C"
                        "trl-Shift-D: Delete</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Noto Sans';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans'; font-style:italic;\">*If the shortcut does not work, click somewhere in the main file manager view, and then try the shortcut again.</span></p></body></html>", nullptr));
        closeButton->setText(QCoreApplication::translate("KeyboardShortcutsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyboardShortcutsDialog: public Ui_KeyboardShortcutsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDSHORTCUTSDIALOG_H
