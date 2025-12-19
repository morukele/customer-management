include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

QT -= gui
QT += sql network xml

TARGET = cm-lib
TEMPLATE = lib
DEFINES += CM_LIB_LIBRARY

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source

SOURCES += \
    source/controllers/command-controller.cpp \
    source/controllers/database-controller.cpp \
    source/controllers/master-controller.cpp \
    source/data/data-decorator.cpp \
    source/data/date-time-decorator.cpp \
    source/data/dropdown-value.cpp \
    source/data/dropdown.cpp \
    source/data/entity.cpp \
    source/data/enumerator-decorator.cpp \
    source/data/int-decorator.cpp \
    source/data/string-decorator.cpp \
    source/framework/command.cpp \
    source/framework/object-factory.cpp \
    source/models/address.cpp \
    source/models/appointment.cpp \
    source/models/client-search.cpp \
    source/models/client.cpp \
    cm_lib.cpp \
    source/models/contact.cpp \
    source/networking/network-access-manager.cpp \
    source/networking/web-request.cpp \
    source/rss/rss-channel.cpp \
    source/rss/rss-image.cpp \
    source/rss/rss-item.cpp \
    source/utilities/xml-helper.cpp

HEADERS += \
    source/controllers/command-controller.h \
    source/controllers/command-controller.h \
    source/controllers/database-controller.h \
    source/controllers/i-database-controller.h \
    source/controllers/master-controller.h \
    source/controllers/navigation-controller.h \
    source/data/data-decorator.h \
    source/data/date-time-decorator.h \
    source/data/dropdown-value.h \
    source/data/dropdown.h \
    source/data/entity-collection.h \
    source/data/entity.h \
    source/data/enumerator-decorator.h \
    source/data/int-decorator.h \
    source/data/string-decorator.h \
    source/framework/command.h \
    source/framework/i-object-factory.h \
    source/framework/object-factory.h \
    source/models/address.h \
    source/models/appointment.h \
    source/models/client-search.h \
    source/models/client.h \
    source/cm_lib_global.h \
    cm_lib.h \
    source/models/contact.h \
    source/networking/i-network-access-manager.h \
    source/networking/i-web-request.h \
    source/networking/network-access-manager.h \
    source/networking/web-request.h \
    source/rss/rss-channel.h \
    source/rss/rss-image.h \
    source/rss/rss-item.h \
    source/utilities/xml-helper.h

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

