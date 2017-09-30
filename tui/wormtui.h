#ifndef WORMTUI_H
#define WORMTUI_H

#include "../engines/worm.h"
#include "mainscreen.h"
#include <vector>

class MainScreen;

class WormTui{

public:

    //constructors
    WormTui(int rows, int cols, MainScreen *m);
    WormTui();
    ~WormTui();

    //methods
    void begin();
    void print();
    void move(int ch);
    void play_again();

    int get();

    //objects
    Worm w;
    MainScreen *main;

    //vars
    int score;
    int cnt;

    bool continue_looping;
};

#endif // WORMTUI_H
