/****************************************************************************
** Meta object code from reading C++ file 'tilesetmodel.h'
**
** Created: Wed Mar 19 15:42:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/tilesetmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tilesetmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__TilesetModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      37,   31,   30,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__TilesetModel[] = {
    "Tiled::Internal::TilesetModel\0\0tiles\0"
    "tilesChanged(QList<Tile*>)\0"
};

void Tiled::Internal::TilesetModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TilesetModel *_t = static_cast<TilesetModel *>(_o);
        switch (_id) {
        case 0: _t->tilesChanged((*reinterpret_cast< const QList<Tile*>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::TilesetModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::TilesetModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_Tiled__Internal__TilesetModel,
      qt_meta_data_Tiled__Internal__TilesetModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::TilesetModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::TilesetModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::TilesetModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__TilesetModel))
        return static_cast<void*>(const_cast< TilesetModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int Tiled::Internal::TilesetModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
