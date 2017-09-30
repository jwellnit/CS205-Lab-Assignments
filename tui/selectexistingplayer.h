#ifndef SELECTEXISTINGPLAYER_H
#define SELECTEXISTINGPLAYER_H

#include "screen.h"
#include "mainscreen.h"

class MainScreen;

class SelectExistingPlayer : public Screen{

public:

    //constructors
    SelectExistingPlayer(MainScreen *m);
    ~SelectExistingPlayer();

    //methods
    void print();
    void displayExistingPlayers();

    //objects
    MainScreen *main;

};

#endif // SELECTEXISTINGPLAYER_H
