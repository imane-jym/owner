/****************************************************************************
** Meta object code from reading C++ file 'mapsdock.h'
**
** Created: Wed Mar 19 15:42:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/mapsdock.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapsdock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__MapsDock[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,
      36,   26,   26,   26, 0x08,
      58,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MapsDock[] = {
    "Tiled::Internal::MapsDock\0\0browse()\0"
    "editedMapsDirectory()\0onMapsDirectoryChanged()\0"
};

void Tiled::Internal::MapsDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapsDock *_t = static_cast<MapsDock *>(_o);
        switch (_id) {
        case 0: _t->browse(); break;
        case 1: _t->editedMapsDirectory(); break;
        case 2: _t->onMapsDirectoryChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Tiled::Internal::MapsDock::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MapsDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MapsDock,
      qt_meta_data_Tiled__Internal__MapsDock, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MapsDock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MapsDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MapsDock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MapsDock))
        return static_cast<void*>(const_cast< MapsDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int Tiled::Internal::MapsDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_Tiled__Internal__MapsView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,
      58,   52,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__MapsView[] = {
    "Tiled::Internal::MapsView\0\0"
    "onMapsDirectoryChanged()\0index\0"
    "onActivated(QModelIndex)\0"
};

void Tiled::Internal::MapsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapsView *_t = static_cast<MapsView *>(_o);
        switch (_id) {
        case 0: _t->onMapsDirectoryChanged(); break;
        case 1: _t->onActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::MapsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::MapsView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_Tiled__Internal__MapsView,
      qt_meta_data_Tiled__Internal__MapsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::MapsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::MapsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::MapsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__MapsView))
        return static_cast<void*>(const_cast< MapsView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int Tiled::Internal::MapsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
