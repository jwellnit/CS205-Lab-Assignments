#include "game.h"

// constructors and desconstructor
// basic constructor
Game::Game(DBTool* db) : DBTable::DBTable(db, gameTable), BaseClass::BaseClass('g')
{ 
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    game_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    // initialize the game information
    name = "";
    score = 0;

    // intitialize the player to null
    player = nullptr;
}

// constructor with provided player owner
Game::Game(Player *p, DBTool* db) : DBTable::DBTable(db, gameTable), BaseClass::BaseClass('g')
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    game_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    // initialize the game information
    name = "";
    score = 0;

    // intitialize the player to provided player
    player = p;
}

// destructor
Game::~Game()
{
    // if valid object, either adds or updates it in the table
    if (isNew && id >= 0) {
        add_row(id, playerId, name, score);
    } else if (!isNew && id >= 0) {
        update_id(id, playerId, name, score);
    } else {

    }
}

// runtime data setting methods
// sets the name of the game
void Game::set_name(string n)
{
    name = n;
}

// sets the final score of the game
void Game::set_score(int s)
{
    score = s;
}

// sets the player owner of the game
void Game::set_player(Player *p)
{
    player = p;
}

// database methods
int Game::get_row_cnt()
{
    return row_cnt;
}

void Game::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Game::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  playerID INT NOT NULL,";
    sql_create += "  name TEXT,";
    sql_create += "  score INT";
    sql_create += " );";

}


bool Game::add_row(int id, int playerId, string name, int score) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, playerID, name, score ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", playerId);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(name);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", score);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_game,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// returns an entry by unique id
bool Game::select_id(int i) {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_id  = "SELECT * FROM ";
    sql_select_id += table_name;
    sql_select_id += "WHERE ";
    sql_select_id += "     id =";
    sql_select_id += i;
    sql_select_id += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_id.c_str(),
                           cb_select_id_game,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// updates an entry by unique id
bool Game::update_id(int id, int playerId, string name, int score) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "playerID = ";
    sprintf (tempval, "%d", playerId);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "name = ";
    sql_update_id += "\"";
    sql_update_id += std::string(name);
    sql_update_id += "\", ";

    sql_update_id += "score = ";
    sprintf (tempval, "%d", playerId);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_game,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// callbacks
int cb_add_row_game(void  *data,
                    int    argc,
                    char **argv,
                    char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Game *obj = (Game *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

int cb_select_id_game(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName)
{



    std::cerr << "cb_select_all being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Game *obj = (Game *) data;
    obj->isNew = false; // provided object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members by table data
    obj->playerId = (int)*argv[1];
    obj->name = argv[2];
    obj->score = (int)*argv[3];

    return 0;
}

int cb_update_id_game(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Game *obj = (Game *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}
