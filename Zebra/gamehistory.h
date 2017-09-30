#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include "game.h"
#include <vector>
#include "dbtable.h"
#include "baseclass.h"

using namespace std;

class Game;  // forward declaration when gamehistory.h is included

class GameHistory: public BaseClass
{
public:
    // constructors and destructor
    GameHistory(int pid, DBTool* db);
    GameHistory(Game *g, int pid, DBTool* db);
    ~GameHistory();

    void add_game(Game *g); // adds new game to the end of history
    Game* get_game(int i); // returns a game from the specified index

    vector<Game*> history; // vector of previously played games

    int playerId; // id of player owner
};

#endif // GAMEHISTORY_H
