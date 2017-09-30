#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include "player.h"
#include "game.h"
#include <vector>
#include <iostream>
#include "dbtable.h"
#include "baseclass.h"

class PlayerGameHistory: public BaseClass
{
public:
    // constructors and destructor
    PlayerGameHistory(DBTool* db);
    PlayerGameHistory(Player *p, DBTool* db);
    ~PlayerGameHistory();

    // data setting methods
    void add_player(Player *p);
    void add_game(Game *g, Player *p);
    void add_game(Game *g, int i);
    void set_score(int i, int score);
    void set_score(Game *g, int score);

    //dynamic statistics
    int num_games_played();
    int num_activce_players();
    float avg_games_per_player();
    int top_game_score();
    float avg_score_games();
    float avg_score_player(Player *p);
    float avg_score_player(int i);
    int get_score(Game *g);

    // database methods
    void populate();

    // object referrences
    vector<Player*> players;
    vector<Game*> games;

    // database
    DBTool* database;
};

#endif // PLAYERGAMEHISTORY_H
