/****************************************************************************
** Meta object code from reading C++ file 'objectpropertiesdialog.h'
**
** Created: Wed Mar 19 15:42:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/objectpropertiesdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectpropertiesdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__ObjectPropertiesDialog[] = {

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
      41,   40,   40,   40, 0x0a,
      58,   40,   40,   40, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__ObjectPropertiesDialog[] = {
    "Tiled::Internal::ObjectPropertiesDialog\0"
    "\0browseForImage()\0imagePathChanged()\0"
};

void Tiled::Internal::ObjectPropertiesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectPropertiesDialog *_t = static_cast<ObjectPropertiesDialog *>(_o);
        switch (_id) {
        case 0: _t->browseForImage(); break;
        case 1: _t->imagePathChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Tiled::Internal::ObjectPropertiesDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::ObjectPropertiesDialog::staticMetaObject = {
    { &PropertiesDialog::staticMetaObject, qt_meta_stringdata_Tiled__Internal__ObjectPropertiesDialog,
      qt_meta_data_Tiled__Internal__ObjectPropertiesDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::ObjectPropertiesDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::ObjectPropertiesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::ObjectPropertiesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__ObjectPropertiesDialog))
        return static_cast<void*>(const_cast< ObjectPropertiesDialog*>(this));
    return PropertiesDialog::qt_metacast(_clname);
}

int Tiled::Internal::ObjectPropertiesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertiesDialog::qt_metacall(_c, _id, _a);
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
