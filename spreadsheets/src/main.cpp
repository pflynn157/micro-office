//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "window.hpp"

int main(int argc, char **argv) {
    QApplication app(argc,argv);

    QFile css(":/style.css");
    QString style = "";
    if (css.open(QFile::ReadOnly)) {
        QTextStream reader(&css);
        while (!reader.atEnd()) {
            style+=reader.readLine();
        }
        css.close();
    }

    Window win;
    win.setStyleSheet(style);
    //win.showMaximized();
    win.show();

    return app.exec();
}
