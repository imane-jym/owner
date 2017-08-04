/****************************************************************************
** Meta object code from reading C++ file 'commandbutton.h'
**
** Created: Wed Mar 19 15:42:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/commandbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__CommandButton[] = {

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
      32,   31,   31,   31, 0x08,
      45,   31,   31,   31, 0x08,
      58,   31,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__CommandButton[] = {
    "Tiled::Internal::CommandButton\0\0"
    "runCommand()\0showDialog()\0populateMenu()\0"
};

void Tiled::Internal::CommandButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommandButton *_t = static_cast<CommandButton *>(_o);
        switch (_id) {
        case 0: _t->runCommand(); break;
        case 1: _t->showDialog(); break;
        case 2: _t->populateMenu(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Tiled::Internal::CommandButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::CommandButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_Tiled__Internal__CommandButton,
      qt_meta_data_Tiled__Internal__CommandButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::CommandButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::CommandButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::CommandButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__CommandButton))
        return static_cast<void*>(const_cast< CommandButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int Tiled::Internal::CommandButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
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
