/****************************************************************************
** Meta object code from reading C++ file 'file_contextmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../file-explorer/src/menu/file_contextmenu.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file_contextmenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileContextMenu_t {
    const uint offsetsAndSize[20];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FileContextMenu_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FileContextMenu_t qt_meta_stringdata_FileContextMenu = {
    {
QT_MOC_LITERAL(0, 15), // "FileContextMenu"
QT_MOC_LITERAL(16, 13), // "onOpenClicked"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 17), // "onOpenWithClicked"
QT_MOC_LITERAL(49, 12), // "onCutClicked"
QT_MOC_LITERAL(62, 13), // "onCopyClicked"
QT_MOC_LITERAL(76, 15), // "onRenameClicked"
QT_MOC_LITERAL(92, 14), // "onTrashClicked"
QT_MOC_LITERAL(107, 16), // "onRestoreClicked"
QT_MOC_LITERAL(124, 15) // "onDeleteClicked"

    },
    "FileContextMenu\0onOpenClicked\0\0"
    "onOpenWithClicked\0onCutClicked\0"
    "onCopyClicked\0onRenameClicked\0"
    "onTrashClicked\0onRestoreClicked\0"
    "onDeleteClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileContextMenu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onOpenClicked(); break;
        case 1: _t->onOpenWithClicked(); break;
        case 2: _t->onCutClicked(); break;
        case 3: _t->onCopyClicked(); break;
        case 4: _t->onRenameClicked(); break;
        case 5: _t->onTrashClicked(); break;
        case 6: _t->onRestoreClicked(); break;
        case 7: _t->onDeleteClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject FileContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_FileContextMenu.offsetsAndSize,
    qt_meta_data_FileContextMenu,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FileContextMenu_t
, QtPrivate::TypeAndForceComplete<FileContextMenu, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FileContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileContextMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int FileContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
