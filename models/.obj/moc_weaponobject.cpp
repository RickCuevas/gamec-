/****************************************************************************
** Meta object code from reading C++ file 'weaponobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sqlobjects/weaponobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weaponobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeaponObject_t {
    QByteArrayData data[11];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeaponObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeaponObject_t qt_meta_stringdata_WeaponObject = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WeaponObject"
QT_MOC_LITERAL(1, 13, 2), // "id"
QT_MOC_LITERAL(2, 16, 5), // "space"
QT_MOC_LITERAL(3, 22, 6), // "attack"
QT_MOC_LITERAL(4, 29, 4), // "name"
QT_MOC_LITERAL(5, 34, 8), // "equipped"
QT_MOC_LITERAL(6, 43, 4), // "main"
QT_MOC_LITERAL(7, 48, 3), // "url"
QT_MOC_LITERAL(8, 52, 10), // "created_at"
QT_MOC_LITERAL(9, 63, 10), // "updated_at"
QT_MOC_LITERAL(10, 74, 13) // "lock_revision"

    },
    "WeaponObject\0id\0space\0attack\0name\0"
    "equipped\0main\0url\0created_at\0updated_at\0"
    "lock_revision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeaponObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,
       9, QMetaType::QString, 0x00095003,
      10, QMetaType::Int, 0x00095003,

       0        // eod
};

void WeaponObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        WeaponObject *_t = static_cast<WeaponObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getspace(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getattack(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getequipped(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getmain(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->geturl(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getcreated_at(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->getupdated_at(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getlock_revision(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WeaponObject *_t = static_cast<WeaponObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setspace(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setattack(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setequipped(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setmain(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->seturl(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setcreated_at(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setupdated_at(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setlock_revision(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject WeaponObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_WeaponObject.data,
      qt_meta_data_WeaponObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WeaponObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeaponObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeaponObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int WeaponObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
