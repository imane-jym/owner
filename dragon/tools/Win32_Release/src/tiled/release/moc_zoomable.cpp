/****************************************************************************
** Meta object code from reading C++ file 'zoomable.h'
**
** Created: Wed Mar 19 15:42:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/zoomable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zoomable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__Zoomable[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   27,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   26,   26,   26, 0x0a,
      62,   26,   26,   26, 0x0a,
      72,   26,   26,   26, 0x0a,
      90,   84,   26,   26, 0x08,
     110,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__Zoomable[] = {
    "Tiled::Internal::Zoomable\0\0scale\0"
    "scaleChanged(qreal)\0zoomIn()\0zoomOut()\0"
    "resetZoom()\0index\0comboActivated(int)\0"
    "comboEdited()\0"
};

void Tiled::Internal::Zoomable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Zoomable *_t = static_cast<Zoomable *>(_o);
        switch (_id) {
        case 0: _t->scaleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->zoomIn(); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->resetZoom(); break;
        case 4: _t->comboActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->comboEdited(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::Zoomable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::Zoomable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tiled__Internal__Zoomable,
      qt_meta_data_Tiled__Internal__Zoomable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::Zoomable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::Zoomable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::Zoomable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__Zoomable))
        return static_cast<void*>(const_cast< Zoomable*>(this));
    return QObject::qt_metacast(_clname);
}

int Tiled::Internal::Zoomable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Tiled::Internal::Zoomable::scaleChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
