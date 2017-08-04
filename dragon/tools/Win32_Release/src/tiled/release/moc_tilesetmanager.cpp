/****************************************************************************
** Meta object code from reading C++ file 'tilesetmanager.h'
**
** Created: Wed Mar 19 15:42:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/tilesetmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tilesetmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__TilesetManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   33,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   66,   32,   32, 0x08,
      92,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__TilesetManager[] = {
    "Tiled::Internal::TilesetManager\0\0"
    "tileset\0tilesetChanged(Tileset*)\0path\0"
    "fileChanged(QString)\0fileChangedTimeout()\0"
};

void Tiled::Internal::TilesetManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TilesetManager *_t = static_cast<TilesetManager *>(_o);
        switch (_id) {
        case 0: _t->tilesetChanged((*reinterpret_cast< Tileset*(*)>(_a[1]))); break;
        case 1: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->fileChangedTimeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::TilesetManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::TilesetManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tiled__Internal__TilesetManager,
      qt_meta_data_Tiled__Internal__TilesetManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::TilesetManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::TilesetManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::TilesetManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__TilesetManager))
        return static_cast<void*>(const_cast< TilesetManager*>(this));
    return QObject::qt_metacast(_clname);
}

int Tiled::Internal::TilesetManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::TilesetManager::tilesetChanged(Tileset * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
