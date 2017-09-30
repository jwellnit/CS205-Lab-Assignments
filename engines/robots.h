#ifndef ROBOTS_H
#define ROBOTS_H

#define MAXENEMIES 20

#include <random>
#include <iostream>
#include <stdio.h>
#include "engine.h"

using namespace std;

class Robots: public Engine
{
public:

    //basic constructors
    Robots(int rows, int cols);
    Robots();
    void operator=(Robots &obj);   // copy assignment
    ~Robots();

    //board methods
    void clear_board();
    void populate_board(int numEnemies);
    void redraw_board();

    //player methods
    //void player_turn();
    bool can_move(int x, int y);
    bool move(char in);
    void teleport();

    //enemy methods
    void pursue(int i);

    //continue methods
    void go();
    void go_safe();

    // engine methods
    void game_over();
    void quit();
    void create_enemy(int x, int y);
    void create_player(int x, int y);
    bool get_status();


    //objects
    int  enemyX    [MAXENEMIES]; // enemy x positions
    int  enemyY    [MAXENEMIES]; // enemy y positions
    int  playerX;                // player x positions
    int  playerY;                // player y positions
    int  score;                  // score
    int  numEnemies;             // current number of enimies to draw
    bool isAlive;                // if player has not been destroyed


};

#endif // ROBOTS_H
