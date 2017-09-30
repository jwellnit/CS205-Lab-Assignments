TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS    += -lncurses \
           -l sqlite3


SOURCES += main.cpp \
    screen.cpp \
    second.cpp \
    robotstui.cpp \
    wormtui.cpp \
    mainscreen.cpp \
    newplayerscreen.cpp \
    selectexistingplayer.cpp \
    displaytopthreeplayers.cpp \
    displaytopthreegames.cpp \
    displaystats.cpp


HEADERS += \
    screen.h \
    second.h \
    robotstui.h \
    wormtui.h \
    mainscreen.h \
    newplayerscreen.h \
    selectexistingplayer.h \
    displaytopthreeplayers.h \
    displaytopthreegames.h \
    displaystats.h

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/worm.h
SOURCES += ../engines/worm.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp

HEADERS += \
    ../Zebra/game.h \
    ../Zebra/gamehistory.h \
    ../Zebra/player.h \
    ../Zebra/playergamehistory.h \
    ../Zebra/dbtool.h \
    ../Zebra/dbtable.h \
    ../Zebra/baseclass.h

SOURCES += \
    ../Zebra/game.cpp \
    ../Zebra/gamehistory.cpp \
    ../Zebra/player.cpp \
    ../Zebra/playergamehistory.cpp \
    ../Zebra/dbtool.cpp \
    ../Zebra/dbtable.cpp \
    ../Zebra/baseclass.cpp
