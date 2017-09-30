TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    worm.cpp \
    robots.cpp \
    engine.cpp

HEADERS += \
    worm.h \
    robots.h \
    engine.h \
    ../Tools/macros.h
