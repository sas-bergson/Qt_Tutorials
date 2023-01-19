TEMPLATE = app

include(../hello_msg_box/hello_msg_box.pri)

CONFIG += c++14 qt debug

QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
RCC_DIR = $$DESTDIR/qrc
UI_DIR = $$DESTDIR/ui

SOURCES += \
    src/main.cpp
