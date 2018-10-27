/****************************************************************************
** Meta object code from reading C++ file 'homepage.h'
**
** Created: Sun May 14 19:00:45 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "homepage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HomePage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x08,
      70,   66,    9,    9, 0x08,
     101,   66,    9,    9, 0x08,
     141,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HomePage[] = {
    "HomePage\0\0on_quitPushButton_clicked()\0"
    "on_menuPushButton_clicked()\0pro\0"
    "readDataHandler(dht22_pro_st*)\0"
    "remoteReadDataHandler(nrf24l01_pro_st*)\0"
    "on_resetPushButton_clicked()\0"
};

void HomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HomePage *_t = static_cast<HomePage *>(_o);
        switch (_id) {
        case 0: _t->on_quitPushButton_clicked(); break;
        case 1: _t->on_menuPushButton_clicked(); break;
        case 2: _t->readDataHandler((*reinterpret_cast< dht22_pro_st*(*)>(_a[1]))); break;
        case 3: _t->remoteReadDataHandler((*reinterpret_cast< nrf24l01_pro_st*(*)>(_a[1]))); break;
        case 4: _t->on_resetPushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HomePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HomePage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomePage,
      qt_meta_data_HomePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HomePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomePage))
        return static_cast<void*>(const_cast< HomePage*>(this));
    return QWidget::qt_metacast(_clname);
}

int HomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
