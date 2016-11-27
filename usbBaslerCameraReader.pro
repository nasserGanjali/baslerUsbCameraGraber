#-------------------------------------------------
#
# Project created by QtCreator 2016-11-26T04:05:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = usbBaslerCameraReader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    usbcamera.cpp \
    stringmodel.cpp

HEADERS  += mainwindow.h \
    usbcamera.h \
    stringmodel.h

FORMS    += mainwindow.ui

INCLUDEPATH += /opt/pylon5/include
LIBS += -L/opt/pylon5/lib -Wl,-E -lpylonbase -lpylonutility -lGenApi_gcc_v3_0_Basler_pylon_v5_0 -lGCBase_gcc_v3_0_Basler_pylon_v5_0 -Wl,--enable-new-dtags -Wl,-rpath,/opt/pylon5/lib
