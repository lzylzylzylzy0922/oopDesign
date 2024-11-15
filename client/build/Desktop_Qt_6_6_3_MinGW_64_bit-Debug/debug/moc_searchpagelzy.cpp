/****************************************************************************
** Meta object code from reading C++ file 'searchpagelzy.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../searchpagelzy.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchpagelzy.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSearchPageLzyENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSearchPageLzyENDCLASS = QtMocHelpers::stringData(
    "SearchPageLzy",
    "recvSignal",
    "",
    "AccountLzy*",
    "account",
    "on_searchButton_clicked",
    "onInfoItemClicked",
    "accountId"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSearchPageLzyENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[24];
    char stringdata6[18];
    char stringdata7[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSearchPageLzyENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSearchPageLzyENDCLASS_t qt_meta_stringdata_CLASSSearchPageLzyENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "SearchPageLzy"
        QT_MOC_LITERAL(14, 10),  // "recvSignal"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 11),  // "AccountLzy*"
        QT_MOC_LITERAL(38, 7),  // "account"
        QT_MOC_LITERAL(46, 23),  // "on_searchButton_clicked"
        QT_MOC_LITERAL(70, 17),  // "onInfoItemClicked"
        QT_MOC_LITERAL(88, 9)   // "accountId"
    },
    "SearchPageLzy",
    "recvSignal",
    "",
    "AccountLzy*",
    "account",
    "on_searchButton_clicked",
    "onInfoItemClicked",
    "accountId"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSearchPageLzyENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       5,    0,   35,    2, 0x08,    3 /* Private */,
       6,    2,   36,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject SearchPageLzy::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSearchPageLzyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSearchPageLzyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSearchPageLzyENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SearchPageLzy, std::true_type>,
        // method 'recvSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AccountLzy *, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onInfoItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AccountLzy *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void SearchPageLzy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchPageLzy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recvSignal((*reinterpret_cast< std::add_pointer_t<AccountLzy*>>(_a[1]))); break;
        case 1: _t->on_searchButton_clicked(); break;
        case 2: _t->onInfoItemClicked((*reinterpret_cast< std::add_pointer_t<AccountLzy*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
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
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AccountLzy* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *SearchPageLzy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchPageLzy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSearchPageLzyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SearchPageLzy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
