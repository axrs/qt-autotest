#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T19:39:22
#
#-------------------------------------------------

QT       += core testlib
QT       -= gui

TARGET = AutoTest
TEMPLATE = app

SOURCES += main.cpp

CONFIG += mobility
MOBILITY =

HEADERS += \
    autotest.h \
    testexample.h

OTHER_FILES += AutoTest.pri

DISTFILES += \
    readme.md
