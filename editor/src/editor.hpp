//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QKeyEvent>
#include <QMenu>
#include <QContextMenuEvent>
#include <QTextCharFormat>
#include <QMimeData>
#include <qsourcerepository.h>
#include <qsourcehighliter.h>

#include "finder.hpp"
#include "window.hpp"

class Finder;
class TextEdit;

class Editor : public QFrame {
    Q_OBJECT
    friend class TextEdit;
public:
    static bool autoindent;
    static QString colorID;
    static void updateSettings();
    explicit Editor(QString path, Window *parent);
    TextEdit *editorWidget();
    void updateFont();
    void updateTabWidth();
    bool isUntitled();
    void setUntitled(bool untitled);
    QString path();
    void setPath(QString path);
    bool isModified();
    void setModified(bool mod);
    void setEditorText(QString text);
    void syntaxHighlight(QString id);
    QString currentID();
    void setHasFoundText(bool found);
    bool hasFoundText();
    void setSavedContent(QString content);
    QString saveContent();
    void displayFinder();
protected:
    void contextMenuEvent(QContextMenuEvent *);
private:
    Window *parent;
    QVBoxLayout *layout;
    TextEdit *editor;
    Finder *finder;
    QString filePath;
    QSourceHighliter *highlight;
    QString langName = "";
    bool modified = false;
    bool foundText = false;
    QString lastSavedContent = "";
private slots:
    void onModified();
    void highlightCurrentLine();
};

class TextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit TextEdit(Editor *p);
protected:
    bool canInsertFromMimeData(const QMimeData *source);
    void insertFromMimeData(const QMimeData *source);
    void keyPressEvent(QKeyEvent *event);
private:
    Editor *parent;
    bool indent_next = false;
    bool unindent_next = false;
};
