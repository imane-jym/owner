/****************************************************************************
** Meta object code from reading C++ file 'mapscene.h'
**
** Created: Wed Mar 19 15:42:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/mapscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__MapScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   56,   26,   26, 0x08,
      93,   85,   26,   26, 0x08,
     147,  125,   26,   26, 0x08,
     178,   26,   26,   26, 0x08,
     200,  193,   26,   26, 0x08,
     223,   26,   26,   26, 0x08,
     250,   26,   26,   26, 0x08,
     271,  263,   26,   26, 0x08,
     302,  296,   26,   26, 0x08,
     318,  296,   26,   26, 0x08,
     336,  296,   26,   26, 0x08,
     365,  354,   26,   26, 0x08,
     404,  396,   26,   26, 0x08,
     436,  396,   26,   26, 0x08,
     470,  396,   26,   26, 0x08,
     504,   26,   26,   26, 0x08,
     532,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MapScene[] = {
    "Tiled::Internal::MapScene\0\0"
    "selectedObjectItemsChanged()\0visible\0"
    "setGridVisible(bool)\0enabled\0"
    "setShowTileObjectOutlines(bool)\0"
    "highlightCurrentLayer\0"
    "setHighlightCurrentLayer(bool)\0"
    "refreshScene()\0region\0repaintRegion(QRegion)\0"
    "currentLayerIndexChanged()\0mapChanged()\0"
    "tileset\0tilesetChanged(Tileset*)\0index\0"
    "layerAdded(int)\0layerRemoved(int)\0"
    "layerChanged(int)\0imageLayer\0"
    "imageLayerChanged(ImageLayer*)\0objects\0"
    "objectsAdded(QList<MapObject*>)\0"
    "objectsRemoved(QList<MapObject*>)\0"
    "objectsChanged(QList<MapObject*>)\0"
    "updateSelectedObjectItems()\0"
    "syncAllObjectItems()\0"
};

void Tiled::Internal::MapScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapScene *_t = static_cast<MapScene *>(_o);
        switch (_id) {
        case 0: _t->selectedObjectItemsChanged(); break;
        case 1: _t->setGridVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setShowTileObjectOutlines((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setHighlightCurrentLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->refreshScene(); break;
        case 5: _t->repaintRegion((*reinterpret_cast< const QRegion(*)>(_a[1]))); break;
        case 6: _t->currentLayerIndexChanged(); break;
        case 7: _t->mapChanged(); break;
        case 8: _t->tilesetChanged((*reinterpret_cast< Tileset*(*)>(_a[1]))); break;
        case 9: _t->layerAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->layerRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->layerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->imageLayerChanged((*reinterpret_cast< ImageLayer*(*)>(_a[1]))); break;
        case 13: _t->objectsAdded((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 14: _t->objectsRemoved((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 15: _t->objectsChanged((*reinterpret_cast< const QList<MapObject*>(*)>(_a[1]))); break;
        case 16: _t->updateSelectedObjectItems(); break;
        case 17: _t->syncAllObjectItems(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::MapScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MapScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MapScene,
      qt_meta_data_Tiled__Internal__MapScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MapScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MapScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MapScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MapScene))
        return static_cast<void*>(const_cast< MapScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Tiled::Internal::MapScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::MapScene::selectedObjectItemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
