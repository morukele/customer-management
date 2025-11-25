include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

QT -= gui

TARGET = cm-lib
TEMPLATE = lib
DEFINES += CM_LIB_LIBRARY

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source

SOURCES += \
    controllers/master-controller.cpp \
    source/models/client.cpp \
    cm_lib.cpp

HEADERS += \
    controllers/master-controller.h \
    source/models/client.h \
    source/cm_lib_global.h \
    cm_lib.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

