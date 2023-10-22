//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFileDialog>
#include <QFileInfo>

#include "file_actions.hpp"
#include "../tabwidget.hpp"
#include "../parser/parser.hpp"
#include "../sheetwidget.hpp"

void FileActions::newFile() {
    TabWidget::addNewTab();
}

void FileActions::openFile() {
    QFileDialog dialog;
    dialog.setWindowTitle("Open File");
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setDirectory(QDir::homePath());
    if (dialog.exec()) {
        if (dialog.selectedFiles().size()==0) {
            return;
        }
        QString selected = dialog.selectedFiles().at(0);
        if (TabWidget::currentWidget()->isUntitled()&&TabWidget::currentWidget()->isSaved()) {
            TabWidget::currentWidget()->setFile(selected);
            TabWidget::currentWidget()->loadFile();
            TabWidget::setCurrentTitle(QFileInfo(selected).fileName());
        } else {
            TabWidget::addNewTab(selected);
        }
        TabWidget::currentWidget()->setSaved(true);
    }
}

void FileActions::saveFile() {
    if (TabWidget::currentWidget()->isUntitled()) {
        saveFileAs();
        return;
    }
    auto pages = TabWidget::currentWidget()->allPages();
    QString filePath = TabWidget::currentWidget()->file();
    for (int i = 0; i<pages.size(); i++) {
        auto data = TabWidget::currentWidget()->data(pages.at(i));
        auto mathData = TabWidget::currentWidget()->mathData(pages.at(i));
        auto graphData = TabWidget::currentWidget()->graphData(pages.at(i));

        if (!Parser::pageExists(filePath,pages.at(i))) {
            Parser::createPage(filePath,pages.at(i));
        }

        Parser::setData(filePath,pages.at(i),data);
        Parser::setMathData(filePath,pages.at(i),mathData);
        Parser::setGraphData(filePath,pages.at(i),graphData);
    }

    auto filePages = Parser::pages(filePath);
    for (int i = 0; i<filePages.size(); i++) {
        if (!pages.contains(filePages.at(i))) {
            Parser::removePage(filePath,filePages.at(i));
        }
    }

    TabWidget::currentWidget()->setSaved(true);
}

void FileActions::saveFileAs() {
    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setWindowTitle("Save As");
    if (dialog.exec()) {
        if (dialog.selectedFiles().size()==0) {
            return;
        }
        QString selected = dialog.selectedFiles().at(0);
        TabWidget::currentWidget()->setFile(selected);
        TabWidget::setCurrentTitle(QFileInfo(selected).fileName());
        Parser::createFile(selected);

        saveFile();
    }
}
