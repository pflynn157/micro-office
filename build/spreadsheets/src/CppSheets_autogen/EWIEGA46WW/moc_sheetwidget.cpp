/****************************************************************************
** Meta object code from reading C++ file 'sheetwidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../spreadsheets/src/sheetwidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sheetwidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SheetWidget_t {
    const uint offsetsAndSize[28];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SheetWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SheetWidget_t qt_meta_stringdata_SheetWidget = {
    {
QT_MOC_LITERAL(0, 11), // "SheetWidget"
QT_MOC_LITERAL(12, 13), // "onCellChanged"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 17), // "onCellLocoChanged"
QT_MOC_LITERAL(45, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(63, 7), // "current"
QT_MOC_LITERAL(71, 4), // "last"
QT_MOC_LITERAL(76, 25), // "onCurrentDataEnterPressed"
QT_MOC_LITERAL(102, 15), // "onAddTabClicked"
QT_MOC_LITERAL(118, 16), // "onTabDoubleClick"
QT_MOC_LITERAL(135, 5), // "index"
QT_MOC_LITERAL(141, 10), // "onTabClose"
QT_MOC_LITERAL(152, 19), // "onCustomContextMenu"
QT_MOC_LITERAL(172, 3) // "pos"

    },
    "SheetWidget\0onCellChanged\0\0onCellLocoChanged\0"
    "QTableWidgetItem*\0current\0last\0"
    "onCurrentDataEnterPressed\0onAddTabClicked\0"
    "onTabDoubleClick\0index\0onTabClose\0"
    "onCustomContextMenu\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SheetWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    2,   57,    2, 0x08,    2 /* Private */,
       7,    0,   62,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    1,   64,    2, 0x08,    7 /* Private */,
      11,    1,   67,    2, 0x08,    9 /* Private */,
      12,    1,   70,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QPoint,   13,

       0        // eod
};

void SheetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SheetWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCellChanged(); break;
        case 1: _t->onCellLocoChanged((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[2]))); break;
        case 2: _t->onCurrentDataEnterPressed(); break;
        case 3: _t->onAddTabClicked(); break;
        case 4: _t->onTabDoubleClick((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onTabClose((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onCustomContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SheetWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SheetWidget.offsetsAndSize,
    qt_meta_data_SheetWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SheetWidget_t
, QtPrivate::TypeAndForceComplete<SheetWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>


>,
    nullptr
} };


const QMetaObject *SheetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SheetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SheetWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SheetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
