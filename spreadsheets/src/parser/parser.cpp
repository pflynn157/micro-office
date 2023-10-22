//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <iostream>
#include <QFile>

#include "parser.hpp"
#include "xml_parser.hpp"
#include "xlsx_parser.hpp"
#include "csv_parser.hpp"

void Parser::createFile(QString filePath) {
	if (isXlsx(filePath)) {
		XlsxParser::createFile(filePath);
	} else {
		XmlParser::createFile(filePath);
	}
}

QStringList Parser::pages(QString file) {
	if (isXlsx(file)) {
		return XlsxParser::pages(file);
    } else if (file.endsWith(".csv")) {
        //TODO: Clean this up
        QFile f(file);
        QString name = f.fileName();
        QStringList pages;
        pages << name;
        return pages;
	} else {
		return XmlParser::pages(file);
	}
}

bool Parser::pageExists(QString file, QString pageName) {
	if (isXlsx(file)) {
		return XlsxParser::pageExists(file,pageName);
	} else {
		return XmlParser::pageExists(file,pageName);
	}
}

QVector<SheetItem> Parser::allItems(QString file, QString page) {
	if (isXlsx(file)) {
		return XlsxParser::allItems(file,page);
    } else if (file.endsWith(".csv")) {
        return CsvParser::allItems(file,page);
	} else {
		return XmlParser::allItems(file,page);
	}
}

QVector<MathItem> Parser::allMathItems(QString file, QString page) {
	if (isXlsx(file)) {
		return XlsxParser::allMathItems(file,page);
	} else {
		return XmlParser::allMathItems(file,page);
	}
}

QVector<GraphItem> Parser::allGraphItems(QString file, QString page) {
    QVector<GraphItem> items;

    if (!(file.endsWith(".csv") || file.endsWith(".xlsx"))) {
        items = XmlParser::allGraphItems(file,page);
    }

    return items;
}

void Parser::createPage(QString file, QString page) {
	if (isXlsx(file)) {
		XlsxParser::createPage(file,page);
	} else {
		XmlParser::createPage(file,page);
	}	
}

void Parser::removePage(QString file, QString page) {
	if (isXlsx(file)) {
		XlsxParser::removePage(file,page);
	} else {
		XmlParser::removePage(file,page);
	}
}

void Parser::setData(QString file, QString page, QVector<SheetItem> items) {
	if (isXlsx(file)) {
		XlsxParser::setData(file,page,items);
    } else if (file.endsWith(".csv")) {
        CsvParser::setData(file,page,items);
	} else {
		XmlParser::setData(file,page,items);
	}
}

void Parser::setMathData(QString file, QString page, QVector<MathItem> items) {
	if (isXlsx(file)) {
		XlsxParser::setMathData(file,page,items);
	} else {
		XmlParser::setMathData(file,page,items);
	}
}

void Parser::setGraphData(QString file, QString page, QVector<GraphItem> items) {
    if (!(file.endsWith(".csv") || file.endsWith(".xlsx"))) {
        XmlParser::setGraphData(file,page,items);
    }
}

bool Parser::isXlsx(QString file) {
	if (file.endsWith(".xlsx")) {
		return true;
	} else {
		return false;
	}
}

