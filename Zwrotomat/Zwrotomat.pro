QT       += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    codedisplay.cpp \
    commentextractor.cpp \
    eksporter.cpp \
    filereadingutils.cpp \
    generatorwindow.cpp \
    gitform.cpp \
    gitwrapper.cpp \
    highlighter.cpp \
    htmlformater.cpp \
    importer.cpp \
    itemdisplay.cpp \
    linenumberarea.cpp \
    main.cpp \
    mainwindow.cpp \
    multifilecomment.cpp \

HEADERS += \
    codedisplay.h \
    commentextractor.h \
    eksporter.h \
    filereadingutils.h \
    generatorwindow.h \
    gitform.h \
    gitwrapper.h \
    highlighter.h \
    htmlformater.h \
    importer.h \
    itemdisplay.h \
    linenumberarea.h \
    mainwindow.h \
    multifilecomment.h \

FORMS += \
    Mainwindow.ui \
    eksporter.ui \
    generatorwindow.ui \
    gitform.ui \
    importer.ui \
    itemdisplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES = resources.qrc
