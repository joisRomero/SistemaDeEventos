QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    disponibilidad.cpp \
    evento.cpp \
    listadisponibilidad.cpp \
    listaeventos.cpp \
    main.cpp \
    mainwindow.cpp \
    nodoevento.cpp \
    vermas.cpp

HEADERS += \
    disponibilidad.h \
    evento.h \
    listadisponibilidad.h \
    listaeventos.h \
    mainwindow.h \
    nodoevento.h \
    vermas.h

FORMS += \
    mainwindow.ui \
    vermas.ui

RC_ICONS = icono.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
