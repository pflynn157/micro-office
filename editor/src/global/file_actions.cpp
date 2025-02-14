//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFileDialog>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFileInfo>

#include <global/file_actions.hpp>
#include <global/recent.hpp>
#include <tabpane.hpp>
#include <window.hpp>
#include <main_toolbar.hpp>

void FileActions::newFile() {
    TabPane::addNewUntitledTab();
}

void FileActions::openFile() {
    QFileDialog dialog;
    dialog.setWindowTitle("Open");

    if (dialog.exec()) {
        if (dialog.selectedFiles().size()==0) {
            return;
        }

        QStringList selected = dialog.selectedFiles();
        for (int i = 0; i<selected.size(); i++) {
            int count = TabPane::tabs->count();
            bool found = false;
            for (int j = 0; j<count; j++) {
                QString currentPath = TabPane::widgetAt(j)->path();
                if (currentPath==selected.at(i)) {
                    TabPane::tabs->setCurrentIndex(j);
                    found = true;
                    break;
                }
            }
            if (!found) {
                processOpenFile(selected.at(i));
            }
        }
    }
}

void FileActions::processOpenFile(QString file) {
    Recent::addRecentItem(file);
    if ((TabPane::currentWidget()->isUntitled())&&(TabPane::currentWidget()->isModified()==false)) {
        TabPane::setCurrentTabPath(file);
        TabPane::setCurrentTabTitle(QFileInfo(file).fileName());
    } else {
        TabPane::addNewTab(file);
    }
    QString text = fileContents(file);
    TabPane::setCurrentTabText(text);
    TabPane::currentWidget()->setModified(false);
}

void FileActions::saveFile(QString path) {
    QFile file(path);
    if (!file.exists()) {
        saveFileAs();
        return;
    }

    if (file.open(QFile::WriteOnly)) {
        QTextStream writer(&file);
        if (path.endsWith(".rtf")) {
            writer << TabPane::currentEditor()->toHtml();
        } else {
            writer << TabPane::currentTabText();
        }
    }

    TabPane::currentWidget()->setModified(false);
}

void FileActions::saveFile() {
    saveFile(TabPane::currentWidget()->path());
}

void FileActions::saveFileAs() {
    QFileDialog dialog;
    dialog.setDirectory(QDir::homePath());
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setWindowTitle("Save File As");
    int ret = dialog.exec();

    if (ret==QFileDialog::Accepted) {
        QString selected = dialog.selectedFiles().at(0);

        if (!TabPane::currentWidget()->isUntitled()) {
            QString text = TabPane::currentTabText();
            TabPane::addNewTab(selected);
            TabPane::setCurrentTabText(text);
        }

        TabPane::setCurrentTabPath(selected);
        TabPane::setCurrentTabTitle(QFileInfo(selected).fileName());
        Window::setStatusBarPath(selected);
        
        QFile(selected).open(QFile::ReadWrite);
        saveFile(selected);
    }
}

QString FileActions::fileContents(QString path) {
    QFile file(path);
    QString content = "";

    if (file.open(QFile::ReadOnly)) {
        QTextStream reader(&file);

        while (!reader.atEnd()) {
            content+=reader.readLine()+"\n";
        }
    }

    return content;
}

