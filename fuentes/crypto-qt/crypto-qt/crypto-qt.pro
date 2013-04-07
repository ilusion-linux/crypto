#-------------------------------------------------
#
# Project created by QtCreator 2013-03-03T21:27:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crypto-qt
TEMPLATE = app


SOURCES += main.cpp\
        vtnmenuprincipal.cpp \
    informacion.cpp \
    verextenciones.cpp \
    ../../buscador.cpp \
    ayuda.cpp

HEADERS  += vtnmenuprincipal.h \
    informacion.h \
    verextenciones.h \
    ../../buscador.h \
    ayuda.h

FORMS    += vtnmenuprincipal.ui \
    informacion.ui \
    verextenciones.ui \
    ayuda.ui

RESOURCES += \
    imagenes/imagenes-crypto.qrc

OTHER_FILES +=
