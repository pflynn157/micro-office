//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QDialog>
#include <QString>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>

class AppChooserDialog : public QDialog {
    Q_OBJECT
public:
    explicit AppChooserDialog(QString currentFile);
    ~AppChooserDialog();
private:
    QString currentFilePath;
    QVBoxLayout *layout;
    QTreeWidget *treeView;
    QDialogButtonBox *dialogButtons;
    QTreeWidgetItem *suggestedApps;
    QTreeWidgetItem *allApps;
    void loadAll(bool suggested);
    QStringList fileContent(QString file);
    QString secondHalf(QString line);
    void launchApp(QString exe);
private slots:
    void onItemDoubleClicked(QTreeWidgetItem *item);
    void onCancelClicked();
    void onOkClicked();
};
