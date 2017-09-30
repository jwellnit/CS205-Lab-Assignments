#ifndef NEWPLAYERSCREEN_H
#define NEWPLAYERSCREEN_H

#import "screen.h"
#import "mainscreen.h"

class MainScreen;

class NewPlayerScreen
{
public:

    //constructors
    NewPlayerScreen(MainScreen *m);
    ~NewPlayerScreen();

    //objects
    MainScreen* m;
    Player* get_new_player();

    //vars
    void go(MainScreen *m);
    void print();

};

#endif // NEWPLAYERSCREEN_H
