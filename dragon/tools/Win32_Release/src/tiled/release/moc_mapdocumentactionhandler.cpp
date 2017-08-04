/****************************************************************************
** Meta object code from reading C++ file 'mapdocumentactionhandler.h'
**
** Created: Wed Mar 19 15:42:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/mapdocumentactionhandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapdocumentactionhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__MapDocumentActionHandler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      55,   43,   42,   42, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   42,   42,   42, 0x0a,
     100,   42,   42,   42, 0x0a,
     113,   42,   42,   42, 0x0a,
     128,   42,   42,   42, 0x0a,
     146,   42,   42,   42, 0x0a,
     161,   42,   42,   42, 0x0a,
     178,   42,   42,   42, 0x0a,
     194,   42,   42,   42, 0x0a,
     211,   42,   42,   42, 0x0a,
     228,   42,   42,   42, 0x0a,
     250,   42,   42,   42, 0x0a,
     268,   42,   42,   42, 0x0a,
     282,   42,   42,   42, 0x0a,
     298,   42,   42,   42, 0x0a,
     312,   42,   42,   42, 0x0a,
     332,   42,   42,   42, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MapDocumentActionHandler[] = {
    "Tiled::Internal::MapDocumentActionHandler\0"
    "\0mapDocument\0mapDocumentChanged(MapDocument*)\0"
    "selectAll()\0selectNone()\0copyPosition()\0"
    "cropToSelection()\0addTileLayer()\0"
    "addObjectGroup()\0addImageLayer()\0"
    "duplicateLayer()\0mergeLayerDown()\0"
    "selectPreviousLayer()\0selectNextLayer()\0"
    "moveLayerUp()\0moveLayerDown()\0"
    "removeLayer()\0toggleOtherLayers()\0"
    "updateActions()\0"
};

void Tiled::Internal::MapDocumentActionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapDocumentActionHandler *_t = static_cast<MapDocumentActionHandler *>(_o);
        switch (_id) {
        case 0: _t->mapDocumentChanged((*reinterpret_cast< MapDocument*(*)>(_a[1]))); break;
        case 1: _t->selectAll(); break;
        case 2: _t->selectNone(); break;
        case 3: _t->copyPosition(); break;
        case 4: _t->cropToSelection(); break;
        case 5: _t->addTileLayer(); break;
        case 6: _t->addObjectGroup(); break;
        case 7: _t->addImageLayer(); break;
        case 8: _t->duplicateLayer(); break;
        case 9: _t->mergeLayerDown(); break;
        case 10: _t->selectPreviousLayer(); break;
        case 11: _t->selectNextLayer(); break;
        case 12: _t->moveLayerUp(); break;
        case 13: _t->moveLayerDown(); break;
        case 14: _t->removeLayer(); break;
        case 15: _t->toggleOtherLayers(); break;
        case 16: _t->updateActions(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::MapDocumentActionHandler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MapDocumentActionHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MapDocumentActionHandler,
      qt_meta_data_Tiled__Internal__MapDocumentActionHandler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MapDocumentActionHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MapDocumentActionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MapDocumentActionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MapDocumentActionHandler))
        return static_cast<void*>(const_cast< MapDocumentActionHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int Tiled::Internal::MapDocumentActionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::MapDocumentActionHandler::mapDocumentChanged(MapDocument * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
