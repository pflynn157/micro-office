/****************************************************************************
** Meta object code from reading C++ file 'maintoolbar.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../spreadsheets/src/maintoolbar.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maintoolbar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainToolbar_t {
    const uint offsetsAndSize[32];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainToolbar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainToolbar_t qt_meta_stringdata_MainToolbar = {
    {
QT_MOC_LITERAL(0, 11), // "MainToolbar"
QT_MOC_LITERAL(12, 16), // "onNewFileClicked"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 13), // "onOpenClicked"
QT_MOC_LITERAL(44, 13), // "onSaveClicked"
QT_MOC_LITERAL(58, 15), // "onSaveAsClicked"
QT_MOC_LITERAL(74, 13), // "onBoldClicked"
QT_MOC_LITERAL(88, 15), // "onItalicClicked"
QT_MOC_LITERAL(104, 18), // "onUnderlineClicked"
QT_MOC_LITERAL(123, 13), // "onFontChanged"
QT_MOC_LITERAL(137, 4), // "font"
QT_MOC_LITERAL(142, 17), // "onFontSizeChanged"
QT_MOC_LITERAL(160, 3), // "val"
QT_MOC_LITERAL(164, 12), // "onCutClicked"
QT_MOC_LITERAL(177, 13), // "onCopyClicked"
QT_MOC_LITERAL(191, 14) // "onPasteClicked"

    },
    "MainToolbar\0onNewFileClicked\0\0"
    "onOpenClicked\0onSaveClicked\0onSaveAsClicked\0"
    "onBoldClicked\0onItalicClicked\0"
    "onUnderlineClicked\0onFontChanged\0font\0"
    "onFontSizeChanged\0val\0onCutClicked\0"
    "onCopyClicked\0onPasteClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainToolbar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    1,   93,    2, 0x08,    8 /* Private */,
      11,    1,   96,    2, 0x08,   10 /* Private */,
      13,    0,   99,    2, 0x08,   12 /* Private */,
      14,    0,  100,    2, 0x08,   13 /* Private */,
      15,    0,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainToolbar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onNewFileClicked(); break;
        case 1: _t->onOpenClicked(); break;
        case 2: _t->onSaveClicked(); break;
        case 3: _t->onSaveAsClicked(); break;
        case 4: _t->onBoldClicked(); break;
        case 5: _t->onItalicClicked(); break;
        case 6: _t->onUnderlineClicked(); break;
        case 7: _t->onFontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 8: _t->onFontSizeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->onCutClicked(); break;
        case 10: _t->onCopyClicked(); break;
        case 11: _t->onPasteClicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainToolbar::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_meta_stringdata_MainToolbar.offsetsAndSize,
    qt_meta_data_MainToolbar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainToolbar_t
, QtPrivate::TypeAndForceComplete<MainToolbar, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFont, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainToolbar.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int MainToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
