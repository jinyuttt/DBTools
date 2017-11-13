#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T13:03:57
#
#-------------------------------------------------

QT       += sql

QT       -= gui

QT     +=core
TARGET = DBComTools
TEMPLATE = lib

DEFINES += DBCOMTOOLS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += dbcomtools.cpp \
    connectionpool.cpp \
    dbsql.cpp \
    datacloumn.cpp \
    datarow.cpp \
    datatable.cpp \
    datatabletojson.cpp \
    dbargmodel.cpp \
    dbresult.cpp \
    resultcode.cpp

HEADERS += dbcomtools.h\
        dbcomtools_global.h \
    connectionpool.h \
    dbsql.h \
    datacloumn.h \
    datarow.h \
    datatable.h \
    datatabletojson.h \
    dbargmodel.h \
    sqltype.h \
    dbresult.h \
    resultcode.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
DESTDIR         = ../plugins
