#ifndef Screen_H
#define Screen_H

#include <iostream>
#include <curses.h>
#include <string>

using namespace std;

class Screen{
public:

    //constructors
    Screen();
    ~Screen();

    //methods
    void draw_screen(int v);
    void set_up();

    //vars
    bool continue_looping;
};

#endif Screen_H
