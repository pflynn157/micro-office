/****************************************************************************
** Meta object code from reading C++ file 'folder_contextmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../file-explorer/src/menu/folder_contextmenu.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'folder_contextmenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FolderContextMenu_t {
    const uint offsetsAndSize[18];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FolderContextMenu_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FolderContextMenu_t qt_meta_stringdata_FolderContextMenu = {
    {
QT_MOC_LITERAL(0, 17), // "FolderContextMenu"
QT_MOC_LITERAL(18, 16), // "onOpenTabClicked"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 12), // "onCutClicked"
QT_MOC_LITERAL(49, 13), // "onCopyClicked"
QT_MOC_LITERAL(63, 15), // "onRenameClicked"
QT_MOC_LITERAL(79, 20), // "onTrashFolderClicked"
QT_MOC_LITERAL(100, 22), // "onRestoreFolderClicked"
QT_MOC_LITERAL(123, 21) // "onDeleteFolderClicked"

    },
    "FolderContextMenu\0onOpenTabClicked\0\0"
    "onCutClicked\0onCopyClicked\0onRenameClicked\0"
    "onTrashFolderClicked\0onRestoreFolderClicked\0"
    "onDeleteFolderClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FolderContextMenu[] = {

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
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FolderContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FolderContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onOpenTabClicked(); break;
        case 1: _t->onCutClicked(); break;
        case 2: _t->onCopyClicked(); break;
        case 3: _t->onRenameClicked(); break;
        case 4: _t->onTrashFolderClicked(); break;
        case 5: _t->onRestoreFolderClicked(); break;
        case 6: _t->onDeleteFolderClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject FolderContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_FolderContextMenu.offsetsAndSize,
    qt_meta_data_FolderContextMenu,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FolderContextMenu_t
, QtPrivate::TypeAndForceComplete<FolderContextMenu, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FolderContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FolderContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FolderContextMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int FolderContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
