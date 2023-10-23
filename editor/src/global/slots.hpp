//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QObject>
#include <QString>
#include <QMainWindow>

class Slots : public QObject {
    Q_OBJECT
public slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveFileAsSlot();
    void quitSlot(QMainWindow *window);
    void cutSlot();
    void copySlot();
    void pasteSlot();
    void selectAllSlot();
    void undoSlot();
    void redoSlot();
};
