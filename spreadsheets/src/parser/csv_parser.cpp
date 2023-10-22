//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QFile>
#include <QTextStream>
#include <iostream>

#include "csv_parser.hpp"

SheetItem defaultItem() {
    SheetItem item;
    item.bgColor = Qt::white;
    item.fgColor = Qt::black;
    item.spanx = 0;
    item.spany = 0;
    item.colWidth = 10;
    item.rowWidth = 10;
    return item;
}

QVector<SheetItem> CsvParser::allItems(QString file, QString page) {
    QVector<SheetItem> items;
    
    auto lines = fileLines(file);
    int x = 0;
    int y = 0;
    
    for (QString ln : lines) {
        y = 0;
        auto parts = lineParts(ln);
        
        for (QString ln2 : parts) {
            SheetItem item = defaultItem();
            item.data = ln2;
            item.x = x;
            item.y = y;
            items.push_back(item);
            
            y++;
        }
        
        x++;
    }
    
    return items;
}

void CsvParser::setData(QString file, QString page, QVector<SheetItem> items) {
    int lastY = 0;
    QString currentLn = "";
    QStringList contents;
    
    for (SheetItem item : items) {
        currentLn+=item.data+",";
        
        if (item.y!=lastY) {
            contents.push_back(currentLn);
            currentLn = "";
            lastY = item.y;
        }
    }
    
    std::cout << "THE FILE" << std::endl;
    for (QString ln : contents) {
        std::cout << ln.toStdString() << std::endl;
    }
}

QStringList CsvParser::fileLines(QString file) {
    QStringList lines;
    
    QFile f(file);
    if (f.open(QFile::ReadWrite)) {
        QTextStream reader(&f);
        
        while (!reader.atEnd()) {
            QString line = reader.readLine();
            lines.append(line);
        }
    }
    
    return lines;
}

QStringList CsvParser::lineParts(QString line) {
    QStringList parts;
    
    QString current = "";
    bool inQuotes = false;
    
    for (QChar c : line) {
        if ((c==',' || c==';') && inQuotes==false) {
            parts << current;
            current = "";
        } else if (c=='\"') {
            if (inQuotes) {
                inQuotes = false;
            } else {
                inQuotes = true;
            }
        } else {
            current += c;
        }
    }
    
    parts << current;
    
    return parts;
}
