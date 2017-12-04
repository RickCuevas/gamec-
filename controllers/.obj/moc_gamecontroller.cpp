/****************************************************************************
** Meta object code from reading C++ file 'gamecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameController_t {
    QByteArrayData data[16];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameController_t qt_meta_stringdata_GameController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GameController"
QT_MOC_LITERAL(1, 15, 5), // "index"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "welcome"
QT_MOC_LITERAL(4, 30, 4), // "loop"
QT_MOC_LITERAL(5, 35, 5), // "start"
QT_MOC_LITERAL(6, 41, 6), // "battle"
QT_MOC_LITERAL(7, 48, 5), // "equip"
QT_MOC_LITERAL(8, 54, 4), // "nada"
QT_MOC_LITERAL(9, 59, 7), // "staging"
QT_MOC_LITERAL(10, 67, 23), // "randomize_things_to_map"
QT_MOC_LITERAL(11, 91, 4), // "show"
QT_MOC_LITERAL(12, 96, 2), // "id"
QT_MOC_LITERAL(13, 99, 6), // "create"
QT_MOC_LITERAL(14, 106, 4), // "save"
QT_MOC_LITERAL(15, 111, 6) // "remove"

    },
    "GameController\0index\0\0welcome\0loop\0"
    "start\0battle\0equip\0nada\0staging\0"
    "randomize_things_to_map\0show\0id\0create\0"
    "save\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       1,   99, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      15,    1,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,

 // constructors: parameters
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   98,    2, 0x0e /* Public */,

       0        // eod
};

void GameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { GameController *_r = new GameController();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        GameController *_t = static_cast<GameController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->welcome(); break;
        case 2: _t->loop(); break;
        case 3: _t->start(); break;
        case 4: _t->battle(); break;
        case 5: _t->equip(); break;
        case 6: _t->nada(); break;
        case 7: _t->staging(); break;
        case 8: _t->randomize_things_to_map(); break;
        case 9: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->create(); break;
        case 11: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GameController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_GameController.data,
      qt_meta_data_GameController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameController.stringdata0))
        return static_cast<void*>(this);
    return ApplicationController::qt_metacast(_clname);
}

int GameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
