#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "game.h"
#include "gamehistory.h"
#include "dbtable.h"
#include "baseclass.h"

using namespace std;

// forward declarations
class Game;
class GameHistory;

class Player: public DBTable, public BaseClass
{
protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;

public:
    // constructors and destructors
    Player(DBTool* db);
    Player(Game *g, DBTool* db);
    ~Player();

    // runtime data setting methods
    void play_game(Game *g);
    void set_information(string f, string l, string a);
    int get_lastGame_id();

    // database methods
    // returns the row count of the players table
    int get_row_cnt();
    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    // executes specific sql
    bool add_row(int id, string firstName, string lastName,
                 string address, int lastGameId);

    bool select_id(int i);

    bool update_id(int id, string firstName, string lastName,
                   string address, int lastGameId);

    // player information
    string firstName;
    string lastName;
    string address;

    // object references
    Game *lastGame;
    GameHistory *history;

    // db information
    bool isNew;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_player(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_player(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_player(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);


#endif // PLAYER_H
