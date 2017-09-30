#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "dbtable.h"
#include "baseclass.h"

using namespace std;

class Player;  // forward declaration when game.h is included

class Game: public DBTable, public BaseClass
{
protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;

public:
    // constructors and destructors
    Game(DBTool* db);
    Game(Player *p, DBTool* db);
    ~Game();

    // runtime data setting methods
    void set_name(string n);
    void set_score(int s);
    void set_player(Player *p);

    // database methods
    // returns the row count of the games table
    int get_row_cnt();
    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    // executes specific sql
    bool add_row(int id, int playerId, string name, int score);

    bool select_id(int i);

    bool update_id(int id, int playerId, string name, int score);

    // game information
    string name;
    int score;

    // db information
    int playerId;
    bool isNew;

    // object referrences
    Player *player;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_game(void  *data,
                    int    argc,
                    char **argv,
                    char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_game(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_game(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);

#endif
