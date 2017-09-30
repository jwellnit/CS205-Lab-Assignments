#ifndef WORM_H

#define WORM_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <cstring>
#include "engine.h"
#include <curses.h>

class Worm: public Engine{

public:

    //variables
    //char gameBoard [50][25];
    char wormHead;
    int wH_x;
    int wH_y;
    int food;
    int f_x;
    int f_y;
    int xShift = 0;
    int yShift = 0;
    int tailSize = 0;
    int tailCue = 0;
    int tailCoordinateX [100];
    int tailCoordinateY [100];
    char test;
    int lastLink_x;
    int lastLink_y;

    //basic constructors
    Worm(int rows, int cols);
    Worm();
    ~Worm();

    //other constructors
    void operator=(Worm &obj);    // copy assignment

    //methods
    void place_food();
    void hit_food();
    void add_link();
    void clear_shift();
    void draw(int rows, int cols); //draw the board

    //low level array manipulation
    void update_board();
    void update_tail();

    //player action methods
    void left_key();
    void right_key();
    void up_key();
    void down_key();

    //checks
    void check_hit(); //check if the head is run into anything
    void check_key(); //check if a key has been hit
    bool check_move(); //check if the next move is valid

};

#endif // WORM_H
