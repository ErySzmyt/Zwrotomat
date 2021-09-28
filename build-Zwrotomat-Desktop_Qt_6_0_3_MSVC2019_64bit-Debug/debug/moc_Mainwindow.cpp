/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Zwrotomat/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[434];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 27), // "on_treeFileExplorer_clicked"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 11), // "QModelIndex"
QT_MOC_LITERAL(52, 5), // "index"
QT_MOC_LITERAL(58, 28), // "on_actionZ_Folderu_triggered"
QT_MOC_LITERAL(87, 24), // "on_actionPliki_triggered"
QT_MOC_LITERAL(112, 36), // "on_textBrowser_cursorPosition..."
QT_MOC_LITERAL(149, 30), // "on_addingCommentButton_clicked"
QT_MOC_LITERAL(180, 13), // "removeComment"
QT_MOC_LITERAL(194, 4), // "text"
QT_MOC_LITERAL(199, 13), // "selectComment"
QT_MOC_LITERAL(213, 25), // "changePositivityOfComment"
QT_MOC_LITERAL(239, 9), // "isChecked"
QT_MOC_LITERAL(249, 26), // "on_commentEdit_textChanged"
QT_MOC_LITERAL(276, 26), // "on_actionGeneruj_triggered"
QT_MOC_LITERAL(303, 24), // "on_actionPusty_triggered"
QT_MOC_LITERAL(328, 29), // "on_actionKomentarze_triggered"
QT_MOC_LITERAL(358, 22), // "on_actionGit_triggered"
QT_MOC_LITERAL(381, 26), // "on_actionEksport_triggered"
QT_MOC_LITERAL(408, 25) // "on_actionImport_triggered"


    },
    "MainWindow\0on_treeFileExplorer_clicked\0"
    "\0QModelIndex\0index\0on_actionZ_Folderu_triggered\0"
    "on_actionPliki_triggered\0"
    "on_textBrowser_cursorPositionChanged\0"
    "on_addingCommentButton_clicked\0"
    "removeComment\0text\0selectComment\0"
    "changePositivityOfComment\0isChecked\0"
    "on_commentEdit_textChanged\0"
    "on_actionGeneruj_triggered\0"
    "on_actionPusty_triggered\0"
    "on_actionKomentarze_triggered\0"
    "on_actionGit_triggered\0"
    "on_actionEksport_triggered\0"
    "on_actionImport_triggered"

};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo

      15,   14, // methods

       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    0 /* Private */,
       5,    0,  107,    2, 0x08,    2 /* Private */,
       6,    0,  108,    2, 0x08,    3 /* Private */,
       7,    0,  109,    2, 0x08,    4 /* Private */,
       8,    0,  110,    2, 0x08,    5 /* Private */,
       9,    1,  111,    2, 0x08,    6 /* Private */,
      11,    1,  114,    2, 0x08,    8 /* Private */,
      12,    2,  117,    2, 0x08,   10 /* Private */,
      14,    0,  122,    2, 0x08,   13 /* Private */,
      15,    0,  123,    2, 0x08,   14 /* Private */,
      16,    0,  124,    2, 0x08,   15 /* Private */,
      17,    0,  125,    2, 0x08,   16 /* Private */,
      18,    0,  126,    2, 0x08,   17 /* Private */,
      19,    0,  127,    2, 0x08,   18 /* Private */,
      20,    0,  128,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   10,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_treeFileExplorer_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_actionZ_Folderu_triggered(); break;
        case 2: _t->on_actionPliki_triggered(); break;
        case 3: _t->on_textBrowser_cursorPositionChanged(); break;
        case 4: _t->on_addingCommentButton_clicked(); break;
        case 5: _t->removeComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->selectComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->changePositivityOfComment((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 8: _t->on_commentEdit_textChanged(); break;
        case 9: _t->on_actionGeneruj_triggered(); break;
        case 10: _t->on_actionPusty_triggered(); break;
        case 11: _t->on_actionKomentarze_triggered(); break;
        case 12: _t->on_actionGit_triggered(); break;
        case 13: _t->on_actionEksport_triggered(); break;
        case 14: _t->on_actionImport_triggered(); break;

        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)

            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;

        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;

    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
