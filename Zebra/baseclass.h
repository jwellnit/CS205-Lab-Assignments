#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>

using namespace std;

class BaseClass
{
    // Class that contains a counting/id mechanism for classes to inherit from
public:
    BaseClass();
    BaseClass(char k);

    static int id_player;
    static int id_game;

    static int player_row_cnt;
    static int game_row_cnt;

    int id;

    static string playerTable;
    static string gameTable;
};

#endif // BASECLASS_H
