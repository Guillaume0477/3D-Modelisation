/****************************************************************************
** Meta object code from reading C++ file 'myWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/local/interface/myWindow.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x08,
      57,    9,    9,    9, 0x08,
      73,    9,    9,    9, 0x08,
      90,    9,    9,    9, 0x08,
     106,    9,    9,    9, 0x08,
     123,    9,    9,    9, 0x08,
     148,    9,    9,    9, 0x08,
     174,    9,    9,    9, 0x08,
     199,    9,    9,    9, 0x08,
     225,    9,    9,    9, 0x08,
     255,    9,    9,    9, 0x08,
     274,    9,    9,    9, 0x08,
     293,    9,    9,    9, 0x08,
     314,    9,    9,    9, 0x08,
     331,    9,    9,    9, 0x08,
     345,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_myWindow[] = {
    "myWindow\0\0action_quit()\0action_draw()\0"
    "action_wireframe()\0action_u_back()\0"
    "action_u_front()\0action_v_back()\0"
    "action_v_front()\0action_u_back_negative()\0"
    "action_u_front_negative()\0"
    "action_v_back_negative()\0"
    "action_v_front_negative()\0"
    "action_duplicate_boundaries()\0"
    "action_save_grid()\0action_load_grid()\0"
    "action_color_patch()\0action_surface()\0"
    "action_grid()\0action_grid_position()\0"
};

void myWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myWindow *_t = static_cast<myWindow *>(_o);
        switch (_id) {
        case 0: _t->action_quit(); break;
        case 1: _t->action_draw(); break;
        case 2: _t->action_wireframe(); break;
        case 3: _t->action_u_back(); break;
        case 4: _t->action_u_front(); break;
        case 5: _t->action_v_back(); break;
        case 6: _t->action_v_front(); break;
        case 7: _t->action_u_back_negative(); break;
        case 8: _t->action_u_front_negative(); break;
        case 9: _t->action_v_back_negative(); break;
        case 10: _t->action_v_front_negative(); break;
        case 11: _t->action_duplicate_boundaries(); break;
        case 12: _t->action_save_grid(); break;
        case 13: _t->action_load_grid(); break;
        case 14: _t->action_color_patch(); break;
        case 15: _t->action_surface(); break;
        case 16: _t->action_grid(); break;
        case 17: _t->action_grid_position(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData myWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_myWindow,
      qt_meta_data_myWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myWindow))
        return static_cast<void*>(const_cast< myWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int myWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
