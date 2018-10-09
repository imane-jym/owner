/****************************************************************************
** Meta object code from reading C++ file 'quickstampmanager.h'
**
** Created: Wed Mar 19 15:42:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/quickstampmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quickstampmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__QuickStampManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   68,   35,   35, 0x0a,
      96,   68,   35,   35, 0x0a,
     128,  116,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__QuickStampManager[] = {
    "Tiled::Internal::QuickStampManager\0\0"
    "setStampBrush(const TileLayer*)\0index\0"
    "selectQuickStamp(int)\0saveQuickStamp(int)\0"
    "mapDocument\0setMapDocument(MapDocument*)\0"
};

void Tiled::Internal::QuickStampManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QuickStampManager *_t = static_cast<QuickStampManager *>(_o);
        switch (_id) {
        case 0: _t->setStampBrush((*reinterpret_cast< const TileLayer*(*)>(_a[1]))); break;
        case 1: _t->selectQuickStamp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->saveQuickStamp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMapDocument((*reinterpret_cast< MapDocument*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::QuickStampManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::QuickStampManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tiled__Internal__QuickStampManager,
      qt_meta_data_Tiled__Internal__QuickStampManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::QuickStampManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::QuickStampManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::QuickStampManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__QuickStampManager))
        return static_cast<void*>(const_cast< QuickStampManager*>(this));
    return QObject::qt_metacast(_clname);
}

int Tiled::Internal::QuickStampManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::QuickStampManager::setStampBrush(const TileLayer * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
