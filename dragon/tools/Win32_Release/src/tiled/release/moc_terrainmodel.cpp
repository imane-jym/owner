/****************************************************************************
** Meta object code from reading C++ file 'terrainmodel.h'
**
** Created: Wed Mar 19 15:42:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/terrainmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terrainmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__TerrainModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      49,   31,   30,   30, 0x05,
      76,   31,   30,   30, 0x05,
     119,  105,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
     154,  148,   30,   30, 0x08,
     181,   30,   30,   30, 0x08,
     196,  148,   30,   30, 0x08,
     225,   30,   30,   30, 0x08,
     250,  242,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__TerrainModel[] = {
    "Tiled::Internal::TerrainModel\0\0"
    "tileset,terrainId\0terrainAdded(Tileset*,int)\0"
    "terrainRemoved(Tileset*,int)\0tileset,index\0"
    "terrainChanged(Tileset*,int)\0index\0"
    "tilesetAboutToBeAdded(int)\0tilesetAdded()\0"
    "tilesetAboutToBeRemoved(int)\0"
    "tilesetRemoved()\0tileset\0"
    "tilesetNameChanged(Tileset*)\0"
};

void Tiled::Internal::TerrainModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TerrainModel *_t = static_cast<TerrainModel *>(_o);
        switch (_id) {
        case 0: _t->terrainAdded((*reinterpret_cast< Tileset*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->terrainRemoved((*reinterpret_cast< Tileset*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->terrainChanged((*reinterpret_cast< Tileset*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->tilesetAboutToBeAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->tilesetAdded(); break;
        case 5: _t->tilesetAboutToBeRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->tilesetRemoved(); break;
        case 7: _t->tilesetNameChanged((*reinterpret_cast< Tileset*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::TerrainModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::TerrainModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_Tiled__Internal__TerrainModel,
      qt_meta_data_Tiled__Internal__TerrainModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::TerrainModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::TerrainModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::TerrainModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__TerrainModel))
        return static_cast<void*>(const_cast< TerrainModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int Tiled::Internal::TerrainModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::TerrainModel::terrainAdded(Tileset * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tiled::Internal::TerrainModel::terrainRemoved(Tileset * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tiled::Internal::TerrainModel::terrainChanged(Tileset * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
