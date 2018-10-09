/****************************************************************************
** Meta object code from reading C++ file 'mapobjectmodel.h'
**
** Created: Wed Mar 19 15:42:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/mapobjectmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapobjectmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__MapObjectModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   33,   32,   32, 0x05,
      73,   33,   32,   32, 0x05,
     107,   33,   32,   32, 0x05,
     150,   33,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
     190,  184,   32,   32, 0x08,
     206,  184,   32,   32, 0x08,
     224,  184,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MapObjectModel[] = {
    "Tiled::Internal::MapObjectModel\0\0"
    "objects\0objectsAdded(QList<MapObject*>)\0"
    "objectsChanged(QList<MapObject*>)\0"
    "objectsAboutToBeRemoved(QList<MapObject*>)\0"
    "objectsRemoved(QList<MapObject*>)\0"
    "index\0layerAdded(int)\0layerChanged(int)\0"
    "layerAboutToBeRemoved(int)\0"
};

void Tiled::Internal::MapObjectModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapObjectModel *_t = static_cast<MapObjectModel *>(_o);
        switch (_id) {
        case 0: _t->objectsAdded((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 1: _t->objectsChanged((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 2: _t->objectsAboutToBeRemoved((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 3: _t->objectsRemoved((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 4: _t->layerAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->layerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->layerAboutToBeRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::MapObjectModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MapObjectModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MapObjectModel,
      qt_meta_data_Tiled__Internal__MapObjectModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MapObjectModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MapObjectModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MapObjectModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MapObjectModel))
        return static_cast<void*>(const_cast< MapObjectModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int Tiled::Internal::MapObjectModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::MapObjectModel::objectsAdded(const QList<MapObject*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tiled::Internal::MapObjectModel::objectsChanged(const QList<MapObject*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tiled::Internal::MapObjectModel::objectsAboutToBeRemoved(const QList<MapObject*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tiled::Internal::MapObjectModel::objectsRemoved(const QList<MapObject*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
