TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17 -Wall -Wfatal-errors

SOURCES += \
        src/degreeAwards.cpp \
        tests/degreeAwards-Tests.cpp

HEADERS += \
        headers/degreeAwards.h

INCLUDEPATH += headers/

LIBS += -lboost_unit_test_framework

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin
DESTDIR = $$_PRO_FILE_PWD_/bin
