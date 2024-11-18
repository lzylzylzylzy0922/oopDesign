/****************************************************************************
** Meta object code from reading C++ file 'mainpagelzy.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainpagelzy.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpagelzy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainPageLzyENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainPageLzyENDCLASS = QtMocHelpers::stringData(
    "MainPageLzy",
    "showSearchPageLzy",
    "",
    "AccountLzy*",
    "acoount",
    "recvSignal",
    "AccountId",
    "on_comboBox_activated",
    "index",
    "onInfoItemClicked",
    "account",
    "friendAccount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainPageLzyENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[11];
    char stringdata6[10];
    char stringdata7[22];
    char stringdata8[6];
    char stringdata9[18];
    char stringdata10[8];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainPageLzyENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainPageLzyENDCLASS_t qt_meta_stringdata_CLASSMainPageLzyENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "MainPageLzy"
        QT_MOC_LITERAL(12, 17),  // "showSearchPageLzy"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 11),  // "AccountLzy*"
        QT_MOC_LITERAL(43, 7),  // "acoount"
        QT_MOC_LITERAL(51, 10),  // "recvSignal"
        QT_MOC_LITERAL(62, 9),  // "AccountId"
        QT_MOC_LITERAL(72, 21),  // "on_comboBox_activated"
        QT_MOC_LITERAL(94, 5),  // "index"
        QT_MOC_LITERAL(100, 17),  // "onInfoItemClicked"
        QT_MOC_LITERAL(118, 7),  // "account"
        QT_MOC_LITERAL(126, 13)   // "friendAccount"
    },
    "MainPageLzy",
    "showSearchPageLzy",
    "",
    "AccountLzy*",
    "acoount",
    "recvSignal",
    "AccountId",
    "on_comboBox_activated",
    "index",
    "onInfoItemClicked",
    "account",
    "friendAccount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainPageLzyENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   41,    2, 0x0a,    3 /* Public */,
       7,    1,   44,    2, 0x08,    5 /* Private */,
       9,    2,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainPageLzy::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainPageLzyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainPageLzyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainPageLzyENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainPageLzy, std::true_type>,
        // method 'showSearchPageLzy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AccountLzy *, std::false_type>,
        // method 'recvSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_comboBox_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onInfoItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AccountLzy *, std::false_type>,
        QtPrivate::TypeAndForceComplete<AccountLzy *, std::false_type>
    >,
    nullptr
} };

void MainPageLzy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainPageLzy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showSearchPageLzy((*reinterpret_cast< std::add_pointer_t<AccountLzy*>>(_a[1]))); break;
        case 1: _t->recvSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_comboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onInfoItemClicked((*reinterpret_cast< std::add_pointer_t<AccountLzy*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<AccountLzy*>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AccountLzy* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AccountLzy* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainPageLzy::*)(AccountLzy * );
            if (_t _q_method = &MainPageLzy::showSearchPageLzy; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainPageLzy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPageLzy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainPageLzyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainPageLzy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MainPageLzy::showSearchPageLzy(AccountLzy * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
