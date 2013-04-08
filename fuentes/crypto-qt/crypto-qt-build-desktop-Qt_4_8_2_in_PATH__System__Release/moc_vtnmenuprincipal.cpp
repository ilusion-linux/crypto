/****************************************************************************
** Meta object code from reading C++ file 'vtnmenuprincipal.h'
**
** Created: Mon Apr 8 15:12:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../crypto-qt/vtnmenuprincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtnmenuprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VtnMenuPrincipal[] = {

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
      18,   17,   17,   17, 0x08,
      37,   17,   17,   17, 0x08,
      55,   17,   17,   17, 0x08,
      72,   17,   17,   17, 0x08,
      83,   17,   17,   17, 0x08,
      96,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VtnMenuPrincipal[] = {
    "VtnMenuPrincipal\0\0abrirInformacion()\0"
    "seleccionarRuta()\0verExtenciones()\0"
    "ejecutar()\0abrirAyuda()\0limpiar()\0"
};

void VtnMenuPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VtnMenuPrincipal *_t = static_cast<VtnMenuPrincipal *>(_o);
        switch (_id) {
        case 0: _t->abrirInformacion(); break;
        case 1: _t->seleccionarRuta(); break;
        case 2: _t->verExtenciones(); break;
        case 3: _t->ejecutar(); break;
        case 4: _t->abrirAyuda(); break;
        case 5: _t->limpiar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VtnMenuPrincipal::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VtnMenuPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VtnMenuPrincipal,
      qt_meta_data_VtnMenuPrincipal, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VtnMenuPrincipal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VtnMenuPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VtnMenuPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VtnMenuPrincipal))
        return static_cast<void*>(const_cast< VtnMenuPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VtnMenuPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
