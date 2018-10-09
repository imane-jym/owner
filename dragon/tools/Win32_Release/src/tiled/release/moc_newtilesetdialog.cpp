/****************************************************************************
** Meta object code from reading C++ file 'newtilesetdialog.h'
**
** Created: Wed Mar 19 15:42:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/newtilesetdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newtilesetdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__NewTilesetDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      35,   34,   34,   34, 0x08,
      49,   44,   34,   34, 0x08,
      69,   34,   34,   34, 0x08,
      86,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__NewTilesetDialog[] = {
    "Tiled::Internal::NewTilesetDialog\0\0"
    "browse()\0name\0nameEdited(QString)\0"
    "updateOkButton()\0tryAccept()\0"
};

void Tiled::Internal::NewTilesetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewTilesetDialog *_t = static_cast<NewTilesetDialog *>(_o);
        switch (_id) {
        case 0: _t->browse(); break;
        case 1: _t->nameEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateOkButton(); break;
        case 3: _t->tryAccept(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::NewTilesetDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::NewTilesetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Tiled__Internal__NewTilesetDialog,
      qt_meta_data_Tiled__Internal__NewTilesetDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::NewTilesetDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::NewTilesetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::NewTilesetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__NewTilesetDialog))
        return static_cast<void*>(const_cast< NewTilesetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Tiled::Internal::NewTilesetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
