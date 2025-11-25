include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)s

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++14
CONFIG -= app_bundle
CONFIG += qtmoc

TARGET = client-tests
TEMPLATE = app

INCLUDEPATH += source

SOURCES += \
    source/models/client-tests.cpp

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
