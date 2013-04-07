/****************************************************************************
** Meta object code from reading C++ file 'verextenciones.h'
**
** Created: Wed Apr 3 17:59:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../crypto-qt/verextenciones.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verextenciones.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VerExtenciones[] = {

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
      16,   15,   15,   15, 0x08,
      35,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VerExtenciones[] = {
    "VerExtenciones\0\0agregarExtencion()\0"
    "reiniciar()\0"
};

void VerExtenciones::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VerExtenciones *_t = static_cast<VerExtenciones *>(_o);
        switch (_id) {
        case 0: _t->agregarExtencion(); break;
        case 1: _t->reiniciar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VerExtenciones::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VerExtenciones::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VerExtenciones,
      qt_meta_data_VerExtenciones, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VerExtenciones::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VerExtenciones::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VerExtenciones::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VerExtenciones))
        return static_cast<void*>(const_cast< VerExtenciones*>(this));
    return QDialog::qt_metacast(_clname);
}

int VerExtenciones::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
