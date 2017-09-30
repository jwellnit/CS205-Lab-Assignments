TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    playergamehistory.cpp \
    player.cpp \
    game.cpp \
    gamehistory.cpp \
    dbtool.cpp \
    dbtable.cpp \
    baseclass.cpp
HEADERS += \
    playergamehistory.h \
    player.h \
    game.h \
    gamehistory.h \
    dbtool.h \
    dbtable.h \
    baseclass.h

LIBS += -l sqlite3
