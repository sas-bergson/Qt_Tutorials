TEMPLATE = lib

CONFIG += staticlib qt

QT += widgets

OBJECTS_DIR = obj
MOC_DIR = moc
DESTDIR = lib
UI_DIR = include

INCLUDEPATH += $${PWD}/include

HEADERS += include/calculator.hpp

SOURCES += src/calculator.cpp

FORMS += ui/frame.ui

