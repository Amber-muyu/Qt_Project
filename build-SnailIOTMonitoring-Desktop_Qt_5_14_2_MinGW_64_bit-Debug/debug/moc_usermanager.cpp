/****************************************************************************
** Meta object code from reading C++ file 'usermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SnailIOTMonitoring/src/database/usermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserManager_t {
    QByteArrayData data[9];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserManager_t qt_meta_stringdata_UserManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UserManager"
QT_MOC_LITERAL(1, 12, 9), // "userAdded"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "userId"
QT_MOC_LITERAL(4, 30, 11), // "userUpdated"
QT_MOC_LITERAL(5, 42, 8), // "username"
QT_MOC_LITERAL(6, 51, 11), // "userDeleted"
QT_MOC_LITERAL(7, 63, 20), // "authenticationFailed"
QT_MOC_LITERAL(8, 84, 15) // "passwordChanged"

    },
    "UserManager\0userAdded\0\0userId\0userUpdated\0"
    "username\0userDeleted\0authenticationFailed\0"
    "passwordChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       8,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void UserManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->userUpdated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->userDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->authenticationFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->passwordChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManager::userAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManager::userUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManager::userDeleted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManager::authenticationFailed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UserManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManager::passwordChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UserManager.data,
    qt_meta_data_UserManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UserManager::userAdded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserManager::userUpdated(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserManager::userDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserManager::authenticationFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UserManager::passwordChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
