#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T09:40:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConsoleGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
         ../Zebra/baseclass.cpp \
         ../Zebra/dbtable.cpp \
         ../Zebra/dbtool.cpp \
         ../Zebra/game.cpp \
         ../Zebra/gamehistory.cpp \
         ../Zebra/player.cpp \
         ../Zebra/playergamehistory.cpp \
         ../WormGUI/wormgui.cpp \
         ../RobotsGUI/robotsgui.cpp \
         ../engines/robots.cpp \
         ../engines/worm.cpp \
        ../NewPlayerGui/widget.cpp \
        ../ExistingPlayerGui/widget.cpp \
        ../StatGui/widget.cpp \
        ../TopThreeGamesGui/widget.cpp \
        ../TopThreePlayersGui/widget.cpp

HEADERS  += mainwindow.h \
         ../Zebra/baseclass.h \
         ../Zebra/dbtable.h \
         ../Zebra/dbtool.h \
         ../Zebra/game.h \
         ../Zebra/gamehistory.h \
         ../Zebra/player.h \
         ../Zebra/playergamehistory.h \
         ../WormGUI/wormgui.h \
         ../RobotsGUI/robotsgui.h \
         ../engines/robots.h \
         ../engines/worm.h \
        ../NewPlayerGui/widget.h \
        ../ExistingPlayerGui/widget.h \
        ../StatGui/widget.h \
        ../TopThreeGamesGui/widget.h \
        ../TopThreePlayersGui/widget.h

FORMS    += mainwindow.ui \
        ../WormGUI/wormgui.ui \
        ../RobotsGUI/robotsgui.ui \
        ../NewPlayerGui/widget.ui \
        ../ExistingPlayerGui/widget.ui \
        ../StatGui/widget.ui \
        ../TopThreeGamesGui/widget.ui \
        ../TopThreePlayersGui/widget.ui

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

LIBS += -l sqlite3
