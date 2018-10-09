/****************************************************************************
** Meta object code from reading C++ file 'resizedialog.h'
**
** Created: Wed Mar 19 15:42:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/resizedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resizedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__ResizeDialog[] = {

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
      38,   31,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__ResizeDialog[] = {
    "Tiled::Internal::ResizeDialog\0\0bounds\0"
    "updateOffsetBounds(QRect)\0"
};

void Tiled::Internal::ResizeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResizeDialog *_t = static_cast<ResizeDialog *>(_o);
        switch (_id) {
        case 0: _t->updateOffsetBounds((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::ResizeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::ResizeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Tiled__Internal__ResizeDialog,
      qt_meta_data_Tiled__Internal__ResizeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::ResizeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::ResizeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::ResizeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__ResizeDialog))
        return static_cast<void*>(const_cast< ResizeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Tiled::Internal::ResizeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
