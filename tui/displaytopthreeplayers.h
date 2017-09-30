#ifndef DISPLAYTOPTHREEPLAYERS_H
#define DISPLAYTOPTHREEPLAYERS_H

#include "screen.h"
#include "mainscreen.h"

class MainScreen;

class DisplayTopThreePlayers
{
public:

    //constructors
    DisplayTopThreePlayers(MainScreen *m);
    ~DisplayTopThreePlayers();

    //methods
    void begin();
    void print();

    //objects
    MainScreen          *main;
    PlayerGameHistory   *ph;
    vector<Player*>     p;

    Player *p1;
    Player *p2;
    Player *p3;

    //vars
    bool continue_looping;
};

#endif // DISPLAYTOPTHREEPLAYERS_H
