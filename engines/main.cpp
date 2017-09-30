#include <iostream>
#include "worm.h"
#include "robots.h"

using namespace std;

Worm worm;
Robots r;

int main(int argc, char *argv[])
{
    worm.add_link();
    worm.add_link();
    worm.add_link();

    worm.left_key();
    worm.update_board();

    worm.left_key();
    worm.update_board();

    worm.up_key();
    worm.update_board();

    worm.up_key();
    worm.update_board();

    worm.right_key();
    worm.update_board();

    worm.right_key();
    worm.update_board();

    worm.down_key();
    worm.update_board();

    worm.down_key();
    worm.update_board();

    worm.hit_food();
    worm.update_board();
    worm.print_board();
}
