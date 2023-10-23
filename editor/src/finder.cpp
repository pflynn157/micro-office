//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QTextDocument>
#include <QTextCursor>
#include <QTextCharFormat>
#include <iostream>

#include "finder.hpp"
#include "icon.hpp"

Finder::Finder(Editor *edit)
    : find(new QToolButton),
      findNext(new QToolButton),
      replace(new QToolButton),
      entry(new QLineEdit),
      replaceEntry(new QLineEdit),
      close(new QToolButton)
{
    editor = edit;

    this->setMovable(false);
    this->setContextMenuPolicy(Qt::PreventContextMenu);

    find->setText("Find");
    findNext->setText("Find Next");
    replace->setText("Replace");

    close->setToolTip("Close find/replace toolbar");
    close->setIcon(IconManager::getIcon("dialog-close"));

    entry->setClearButtonEnabled(true);
    replaceEntry->setClearButtonEnabled(true);

    connect(find,&QToolButton::clicked,this,&Finder::onFindClicked);
    connect(findNext,&QToolButton::clicked,this,&Finder::onFindNextClicked);
    connect(replace,&QToolButton::clicked,this,&Finder::onReplaceClicked);
    connect(close,&QToolButton::clicked,this,&Finder::onCloseClicked);

    this->addWidget(find);
    this->addWidget(findNext);
    this->addWidget(entry);
    this->addWidget(replace);
    this->addWidget(replaceEntry);
    this->addWidget(close);
}

Finder::~Finder() {
    delete find;
    delete findNext;
    delete entry;
    delete replace;
    delete replaceEntry;
    delete close;
}

void Finder::clear() {
    if (lastEntry.isEmpty()) {
        return;
    }

    bool mod = editor->isModified();

    QTextDocument *doc = editor->editorWidget()->document();
    bool found = false;

    QTextCursor hCursor(doc);
    QTextCursor cursor(doc);

    cursor.beginEditBlock();

    QTextCharFormat firstFormat(hCursor.charFormat());
    QTextCharFormat hFormat = firstFormat;
    hFormat.setBackground(Qt::white);

    while (!hCursor.isNull() && !hCursor.atEnd()) {
        hCursor = doc->find(lastEntry,hCursor,QTextDocument::FindWholeWords);
        if (!hCursor.isNull()) {
            found = true;
            hCursor.movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor);
            hCursor.mergeCharFormat(hFormat);
        }
    }

    cursor.endEditBlock();

    if (!mod) {
        editor->setModified(false);
    }
    index = -1;
    count = 0;
}

void Finder::findText(bool next, bool replaceText) {
    QString toSearch = entry->text();
    if (toSearch.isEmpty()) {
        return;
    }
    if (next && toSearch!=lastEntry) {
        clear();
        findText(false,replaceText);
        index=0;
    }
    lastEntry = toSearch;

    QTextDocument *doc = editor->editorWidget()->document();
    bool found = false;
    int c = 0;

    QTextCursor hCursor(doc);
    QTextCursor cursor(doc);

    cursor.beginEditBlock();

    QTextCharFormat firstFormat(hCursor.charFormat());
    QTextCharFormat hFormat = firstFormat;
    hFormat.setBackground(Qt::yellow);

    while (!hCursor.isNull() && !hCursor.atEnd()) {
        hCursor = doc->find(toSearch,hCursor,QTextDocument::FindWholeWords | QTextDocument::FindCaseSensitively);
        if (!hCursor.isNull()) {
            found = true;
            hCursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
            hCursor.mergeCharFormat(hFormat);
            if (next) {
                if (index==c) {
                    hFormat.setBackground(Qt::gray);
                    hCursor.mergeCharFormat(hFormat);

                    if (replaceText) {
                        hFormat.setBackground(Qt::white);
                        hCursor.mergeCharFormat(hFormat);
                        
                        QString toReplace = replaceEntry->text();
                        QString currentSelect = hCursor.selectedText();
                        
                        if (currentSelect.length() > toSearch.length()) {
                            for (int i = toSearch.length(); i<currentSelect.length(); i++)
                                toReplace += currentSelect.at(i);
                        }
                        
                        if (hCursor.hasSelection()) {
                            hCursor.insertText(toReplace);
                        }
                    }
                } else {
                    hFormat.setBackground(Qt::yellow);
                    hCursor.mergeCharFormat(hFormat);
                }
                c++;
            } else {
                count++;
            }
        }
    }

    cursor.endEditBlock();

    if (!replaceText) {
        editor->setModified(false);
    }
}

void Finder::onFindClicked() {
    clear();
    findText(false,false);
}

void Finder::onFindNextClicked() {
    if (index==count-1) {
        index = 0;
    } else {
        index++;
    }
    findText(true,false);
}

void Finder::onReplaceClicked() {
    if (count==0) {
        findText(false,false);
    }
    findText(true,true);
    onFindClicked();
    onFindNextClicked();
}

void Finder::onCloseClicked() {
    clear();
    this->hide();
}

