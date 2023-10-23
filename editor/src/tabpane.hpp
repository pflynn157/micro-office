//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTabWidget>

#include "cpp_message_widget.hpp"
#include "editor.hpp"
#include "window.hpp"

class TabPane : public QFrame {
    Q_OBJECT
public:
    TabPane(Window *parent);
    ~TabPane();
    static QTabWidget *tabs;
    static CppMessageWidget *rootStatus, *settingsSaved, *buttonHidden;

    static void addNewTab(QString path);
    static void addNewUntitledTab();

    static Editor *currentWidget();
    static TextEdit *currentEditor();
    static Editor *widgetAt(int index);
    static TextEdit *editorAt(int index);

    static void setCurrentTabPath(QString path);
    static void setCurrentTabText(QString text);
    static QString currentTabText();

    static void setCurrentTabTitle(QString title);
private:
    static Window *window;
    QVBoxLayout *layout;
private slots:
    void onTabClosed(int index);
    void onTabChanged();
};
