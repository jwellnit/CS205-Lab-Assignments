#include "baseclass.h"

// Initialize the static variables
int BaseClass::id_player = 0;
int BaseClass::id_game = 0;
int BaseClass::player_row_cnt = 0;
int BaseClass::game_row_cnt = 0;
string BaseClass::playerTable = "";
string BaseClass::gameTable = "";

BaseClass::BaseClass()
{
    // id is irrelevant
    id = -1;
}

BaseClass::BaseClass(char k)
{
    switch (k) {
    case 'g':
        // object is game, increment game id
        id = id_game;
        id_game++;
        break;

    case 'p':
        // object is player, increment player id
        id = id_player;
        id_player++;
        break;

    default:
        // object is neither, id irrelevant
        id = -1;
        break;

    }
}
