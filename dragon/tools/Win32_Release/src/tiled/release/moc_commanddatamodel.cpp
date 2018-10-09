/****************************************************************************
** Meta object code from reading C++ file 'commanddatamodel.h'
**
** Created: Wed Mar 19 15:42:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tiled/src/tiled/commanddatamodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commanddatamodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tiled__Internal__CommandDataModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      62,   40,   35,   34, 0x0a,
      84,   76,   34,   34, 0x0a,
     113,  100,   34,   34, 0x0a,
     125,  100,   34,   34, 0x0a,
     138,  100,   34,   34, 0x0a,
     161,  100,   34,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tiled__Internal__CommandDataModel[] = {
    "Tiled::Internal::CommandDataModel\0\0"
    "bool\0commandIndex,newIndex\0move(int,int)\0"
    "command\0append(Command)\0commandIndex\0"
    "moveUp(int)\0execute(int)\0"
    "executeInTerminal(int)\0remove(int)\0"
};

void Tiled::Internal::CommandDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommandDataModel *_t = static_cast<CommandDataModel *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->append((*reinterpret_cast< const Command(*)>(_a[1]))); break;
        case 2: _t->moveUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->execute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->executeInTerminal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tiled::Internal::CommandDataModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tiled::Internal::CommandDataModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_Tiled__Internal__CommandDataModel,
      qt_meta_data_Tiled__Internal__CommandDataModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tiled::Internal::CommandDataModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tiled::Internal::CommandDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tiled::Internal::CommandDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tiled__Internal__CommandDataModel))
        return static_cast<void*>(const_cast< CommandDataModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int Tiled::Internal::CommandDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
