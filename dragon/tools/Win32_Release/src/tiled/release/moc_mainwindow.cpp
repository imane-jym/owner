/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 19 15:42:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      43,   34,   29,   28, 0x0a,
      61,   28,   28,   28, 0x0a,
      70,   28,   28,   28, 0x0a,
      81,   28,   29,   28, 0x0a,
      92,   28,   29,   28, 0x0a,
     105,   28,   28,   28, 0x0a,
     119,   28,   28,   28, 0x0a,
     130,   28,   28,   28, 0x0a,
     142,   28,   28,   28, 0x0a,
     158,   28,   28,   28, 0x0a,
     164,   28,   28,   28, 0x0a,
     171,   28,   28,   28, 0x0a,
     179,   28,   28,   28, 0x0a,
     189,   28,   28,   28, 0x0a,
     207,   28,   28,   28, 0x0a,
     216,   28,   28,   28, 0x0a,
     226,   28,   28,   28, 0x0a,
     244,  239,   29,   28, 0x0a,
     264,   28,   29,   28, 0x2a,
     283,  277,   28,   28, 0x0a,
     308,   28,   28,   28, 0x0a,
     325,   28,   28,   28, 0x0a,
     346,   28,   28,   28, 0x0a,
     358,   28,   28,   28, 0x0a,
     370,   28,   28,   28, 0x0a,
     390,   28,   28,   28, 0x0a,
     400,   28,   28,   28, 0x0a,
     420,   28,   28,   28, 0x0a,
     436,   28,   28,   28, 0x0a,
     454,   28,   28,   28, 0x0a,
     467,   28,   28,   28, 0x0a,
     484,   28,   28,   28, 0x0a,
     503,   28,   28,   28, 0x0a,
     525,   28,   28,   28, 0x0a,
     549,   28,   28,   28, 0x0a,
     571,   28,   28,   28, 0x0a,
     589,   28,   28,   28, 0x0a,
     614,  608,   28,   28, 0x0a,
     654,  646,   28,   28, 0x0a,
     697,  686,   28,   28, 0x0a,
     740,  728,   28,   28, 0x0a,
     779,  773,   28,   28, 0x0a,
     801,   28,   28,   28, 0x0a,
     820,   28,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MainWindow[] = {
    "Tiled::Internal::MainWindow\0\0bool\0"
    "fileName\0openFile(QString)\0newMap()\0"
    "openFile()\0saveFile()\0saveFileAs()\0"
    "saveAsImage()\0exportAs()\0closeFile()\0"
    "closeAllFiles()\0cut()\0copy()\0paste()\0"
    "delete_()\0openPreferences()\0zoomIn()\0"
    "zoomOut()\0zoomNormal()\0path\0"
    "newTileset(QString)\0newTileset()\0paths\0"
    "newTilesets(QStringList)\0reloadTilesets()\0"
    "addExternalTileset()\0resizeMap()\0"
    "offsetMap()\0editMapProperties()\0"
    "autoMap()\0updateWindowTitle()\0"
    "updateActions()\0updateZoomLabel()\0"
    "aboutTiled()\0openRecentFile()\0"
    "clearRecentFiles()\0editLayerProperties()\0"
    "flipStampHorizontally()\0flipStampVertically()\0"
    "rotateStampLeft()\0rotateStampRight()\0"
    "tiles\0setStampBrush(const TileLayer*)\0"
    "terrain\0setTerrainBrush(const Terrain*)\0"
    "statusInfo\0updateStatusInfoLabel(QString)\0"
    "mapDocument\0mapDocumentChanged(MapDocument*)\0"
    "index\0closeMapDocument(int)\0"
    "autoMappingError()\0autoMappingWarning()\0"
};

void Tiled::Internal::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->openFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->newMap(); break;
        case 2: _t->openFile(); break;
        case 3: { bool _r = _t->saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->saveFileAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->saveAsImage(); break;
        case 6: _t->exportAs(); break;
        case 7: _t->closeFile(); break;
        case 8: _t->closeAllFiles(); break;
        case 9: _t->cut(); break;
        case 10: _t->copy(); break;
        case 11: _t->paste(); break;
        case 12: _t->delete_(); break;
        case 13: _t->openPreferences(); break;
        case 14: _t->zoomIn(); break;
        case 15: _t->zoomOut(); break;
        case 16: _t->zoomNormal(); break;
        case 17: { bool _r = _t->newTileset((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->newTileset();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: _t->newTilesets((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 20: _t->reloadTilesets(); break;
        case 21: _t->addExternalTileset(); break;
        case 22: _t->resizeMap(); break;
        case 23: _t->offsetMap(); break;
        case 24: _t->editMapProperties(); break;
        case 25: _t->autoMap(); break;
        case 26: _t->updateWindowTitle(); break;
        case 27: _t->updateActions(); break;
        case 28: _t->updateZoomLabel(); break;
        case 29: _t->aboutTiled(); break;
        case 30: _t->openRecentFile(); break;
        case 31: _t->clearRecentFiles(); break;
        case 32: _t->editLayerProperties(); break;
        case 33: _t->flipStampHorizontally(); break;
        case 34: _t->flipStampVertically(); break;
        case 35: _t->rotateStampLeft(); break;
        case 36: _t->rotateStampRight(); break;
        case 37: _t->setStampBrush((*reinterpret_cast< const TileLayer*(*)>(_a[1]))); break;
        case 38: _t->setTerrainBrush((*reinterpret_cast< const Terrain*(*)>(_a[1]))); break;
        case 39: _t->updateStatusInfoLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->mapDocumentChanged((*reinterpret_cast< MapDocument*(*)>(_a[1]))); break;
        case 41: _t->closeMapDocument((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->autoMappingError(); break;
        case 43: _t->autoMappingWarning(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MainWindow,
      qt_meta_data_Tiled__Internal__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Tiled::Internal::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
