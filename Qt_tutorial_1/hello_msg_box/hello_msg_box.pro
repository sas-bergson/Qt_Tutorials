TEMPLATE = lib

CONFIG += staticlib qt

QT += widgets

OBJECTS_DIR = obj/
MOC_DIR = moc/
DESTDIR = lib/

INCLUDEPATH += $${PWD}/include

HEADERS += include/hello_msg_box.hpp

SOURCES += src/hello_msg_box.cpp

