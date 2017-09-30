#ifndef DISPLAYSTATS_H
#define DISPLAYSTATS_H

#include "screen.h"
#include "mainscreen.h"

class MainScreen;

class DisplayStats
{
public:

    //basic constructors
    DisplayStats(MainScreen *m); //constructor
    ~DisplayStats(); //destructor

    //methods
    void begin();
    void print();

    //objects
    MainScreen *main;
    Player *p;
    PlayerGameHistory *ph;

    //variables
    int     numGamesPlayed;
    int     numActivcePlayers;
    int     topGameScore;

    float   avgGamesPerPlayer;
    float   avgScoreGames;
    float   avgScorePlayer;

    bool    continue_looping;
};

#endif // DISPLAYSTATS_H
