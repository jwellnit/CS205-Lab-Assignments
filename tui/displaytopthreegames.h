#ifndef DISPLAYTOPTHREEGAMES_H
#define DISPLAYTOPTHREEGAMES_H

#include "screen.h"
#include "mainscreen.h"

class MainScreen;

class DisplayTopThreeGames
{
public:

    //constructors
    DisplayTopThreeGames(MainScreen *m); //constructor
    ~DisplayTopThreeGames(); //destructor

    //methods
    void begin();
    void print();

    //objects
    MainScreen        *main;
    PlayerGameHistory *ph;
    vector<Game*>      g;

    Game *g1;
    Game *g2;
    Game *g3;

    //vars
    bool continue_looping;

};

#endif // DISPLAYTOPTHREEGAMES_H
