QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++14
CONFIG -= app_bundle

TARGET = client-tests
TEMPLATE = app

SOURCES +=  tst_clienttests.cpp
