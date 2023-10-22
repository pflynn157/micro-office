//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTabWidget>
#include <QString>
#include <QToolButton>
#include <QVector>
#include <QStringList>
#include <QTableWidgetItem>

#include "parser/xml_parser.hpp"
#include "tablewidget.hpp"

class SheetWidget : public QWidget {
    Q_OBJECT
public:
    SheetWidget(QString path);
    ~SheetWidget();
    void loadFile();
    QStringList allPages();
    void setData(QVector<SheetItem> itemList, TableWidget *table);
    QVector<SheetItem> data(QString page);
    QVector<MathItem> mathData(QString page);
    QVector<GraphItem> graphData(QString page);
    void setFile(QString path);
    QString file();
    bool isUntitled();
    void setSaved(bool s);
    bool isSaved();
    void mergeSelected();
    void unMergeSelected();
    TableWidget *currentTable();
    QTableWidgetItem *currentCell();
    QString currentPage();
    void insertPage();
    void renamePage(int index);
    int currentIndex();
private:
    QVBoxLayout *layout;
    QLineEdit *currentData;
    QTabWidget *tabs;
    QToolButton *addTab;
    QString filePath;
    bool saved = true;

    void addNewTab(int no);
private slots:
    void onCellChanged();
    void onCellLocoChanged(QTableWidgetItem *current, QTableWidgetItem *last);
    void onCurrentDataEnterPressed();
    void onAddTabClicked();
    void onTabDoubleClick(int index);
    void onTabClose(int index);
    void onCustomContextMenu(QPoint pos);
};
