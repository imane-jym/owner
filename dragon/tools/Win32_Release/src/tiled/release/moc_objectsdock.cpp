/****************************************************************************
** Meta object code from reading C++ file 'objectsdock.h'
**
** Created: Wed Mar 19 15:42:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/objectsdock.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectsdock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__ObjectsDock[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x08,
      46,   29,   29,   29, 0x08,
      77,   70,   29,   29, 0x08,
     107,   29,   29,   29, 0x08,
     126,   29,   29,   29, 0x08,
     142,   29,   29,   29, 0x08,
     167,  161,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__ObjectsDock[] = {
    "Tiled::Internal::ObjectsDock\0\0"
    "updateActions()\0aboutToShowMoveToMenu()\0"
    "action\0triggeredMoveToMenu(QAction*)\0"
    "duplicateObjects()\0removeObjects()\0"
    "objectProperties()\0index\0"
    "documentCloseRequested(int)\0"
};

void Tiled::Internal::ObjectsDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectsDock *_t = static_cast<ObjectsDock *>(_o);
        switch (_id) {
        case 0: _t->updateActions(); break;
        case 1: _t->aboutToShowMoveToMenu(); break;
        case 2: _t->triggeredMoveToMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->duplicateObjects(); break;
        case 4: _t->removeObjects(); break;
        case 5: _t->objectProperties(); break;
        case 6: _t->documentCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::ObjectsDock::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::ObjectsDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_Tiled__Internal__ObjectsDock,
      qt_meta_data_Tiled__Internal__ObjectsDock, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::ObjectsDock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::ObjectsDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::ObjectsDock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__ObjectsDock))
        return static_cast<void*>(const_cast< ObjectsDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int Tiled::Internal::ObjectsDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_Tiled__Internal__ObjectsView[] = {

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
      50,   30,   29,   29, 0x09,
     104,   98,   29,   29, 0x08,
     129,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__ObjectsView[] = {
    "Tiled::Internal::ObjectsView\0\0"
    "selected,deselected\0"
    "selectionChanged(QItemSelection,QItemSelection)\0"
    "index\0onActivated(QModelIndex)\0"
    "selectedObjectsChanged()\0"
};

void Tiled::Internal::ObjectsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectsView *_t = static_cast<ObjectsView *>(_o);
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->onActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->selectedObjectsChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::ObjectsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::ObjectsView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_Tiled__Internal__ObjectsView,
      qt_meta_data_Tiled__Internal__ObjectsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::ObjectsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::ObjectsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::ObjectsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__ObjectsView))
        return static_cast<void*>(const_cast< ObjectsView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int Tiled::Internal::ObjectsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
