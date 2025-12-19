include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)s

QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++14
CONFIG -= app_bundle
CONFIG += qtmoc

TARGET = client-tests
TEMPLATE = app

INCLUDEPATH += source \
    ../cm_lib/source

SOURCES += \
    source/controllers/master-controller-tests.cpp \
    source/data/date-time-decorator-tests.cpp \
    source/data/enumerator-decorator-tests.cpp \
    source/data/int-decorator-tests.cpp \
    source/data/string-decorator-tests.cpp \
    source/main.cpp \
    source/models/client-tests.cpp \
    source/test-suite.cpp

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

HEADERS += source \
    source/controllers/master-controller-tests.h \
    source/data/date-time-decorator-tests.h \
    source/data/enumerator-decorator-tests.h \
    source/data/int-decorator-tests.h \
    source/data/string-decorator-tests.h \
    source/mocks/mock-object-factory.h \
    source/models/client-tests.h \
    source/test-suite.h
