#ifndef ROBOTSTUI_H
#define ROBOTSTUI_H

#include "screen.h"
#include "../engines/robots.h"
#include "mainscreen.h"

class MainScreen;

class RobotsTui
{
public:

    //constructors
    RobotsTui(int rows, int cols, int startEnemies, MainScreen *main);
    RobotsTui(MainScreen *main);
    ~RobotsTui();

    //objects
    Robots      r;
    MainScreen *main;

    //vars
    int  numEnemies;
    bool continue_looping;

    //methods
    void begin();
    void print();
    void play_again();
};

#endif // ROBOTSTUI_H
