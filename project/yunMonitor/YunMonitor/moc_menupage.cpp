/****************************************************************************
** Meta object code from reading C++ file 'menupage.h'
**
** Created: Sun May 14 19:00:46 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menupage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menupage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuPage[] = {

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
      10,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x08,
      71,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MenuPage[] = {
    "MenuPage\0\0on_backPushButton_clicked()\0"
    "on_tempTablePushButton_clicked()\0"
    "on_remotePushButton_clicked()\0"
};

void MenuPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MenuPage *_t = static_cast<MenuPage *>(_o);
        switch (_id) {
        case 0: _t->on_backPushButton_clicked(); break;
        case 1: _t->on_tempTablePushButton_clicked(); break;
        case 2: _t->on_remotePushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MenuPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MenuPage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MenuPage,
      qt_meta_data_MenuPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuPage))
        return static_cast<void*>(const_cast< MenuPage*>(this));
    return QDialog::qt_metacast(_clname);
}

int MenuPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
