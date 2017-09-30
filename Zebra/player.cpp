#include "player.h"

// Constructors and destructors

// basic constructor
Player::Player(DBTool* db) : DBTable::DBTable(db, playerTable), BaseClass::BaseClass('p')
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    player_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    // initialize player information to empty string
    firstName = "";
    lastName = "";
    address = "";

    lastGame = nullptr;// initialize last game to null
    history = new GameHistory(id, db); // create player's game history
}

// constructor with provided first game
Player::Player(Game *g, DBTool* db) : DBTable::DBTable(db, playerTable), BaseClass::BaseClass('p')
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    player_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    // initialize player information to empty string
    firstName = "";
    lastName = "";
    address = "";

    lastGame = g;// initialize last game to game
    history = new GameHistory(g, id, db); // create player's game history w/ game
}

// deconstructor
Player::~Player()
{
    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, firstName, lastName, address, get_lastGame_id());
    } else if (!isNew && id >= 0){
        update_id(id, firstName, lastName, address, get_lastGame_id());
    } else {

    }

    delete history;
}

// runtime data setting methods
// adds a new game to the player
void Player::play_game(Game *g)
{
    history->add_game(g);
    lastGame = g;
}

// sets the player info
void Player::set_information(string f, string l, string a)
{
    firstName = f;
    lastName = l;
    address = a;
}

int Player::get_lastGame_id()
{
    if (lastGame != nullptr) {
        return lastGame->id;
    } else {
        return -1;
    }
}

// database methods
int Player::get_row_cnt()
{
    return row_cnt;
}

void Player::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Player::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  firstName TEXT,";
    sql_create += "  lastName TEXT,";
    sql_create += "  address TEXT,";
    sql_create += "  lastGameID INT";
    sql_create += " );";

}


bool Player::add_row(int id, string firstName, string lastName,
                     string address, int lastGameId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, firstName, lastName, address, lastGameID ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(firstName);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(lastName);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(address);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", lastGameId);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_player,
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

// selects entry by unique id
bool Player::select_id(int i) {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_id  = "SELECT * FROM ";
    sql_select_id += table_name;
    sql_select_id += " WHERE ";
    sql_select_id += "     id = ";
    sql_select_id += to_string(i);
    sql_select_id += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_id.c_str(),
                           cb_select_id_player,
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

// updates entry by unique id
bool Player::update_id(int id, string firstName, string lastName,
                       string address, int lastGameId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "firstName = ";
    sql_update_id += "\"";
    sql_update_id += std::string(firstName);
    sql_update_id += "\", ";

    sql_update_id += "lastName = ";
    sql_update_id += "\"";
    sql_update_id += std::string(lastName);
    sql_update_id += "\", ";

    sql_update_id += "address = ";
    sql_update_id += "\"";
    sql_update_id += std::string(address);
    sql_update_id += "\", ";

    sql_update_id += "lastGameID = ";
    sprintf (tempval, "%d", lastGameId);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_player,
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
int cb_add_row_player(void  *data,
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

    Player *obj = (Player *) data;

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

int cb_select_id_player(void  *data,
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

    Player *obj = (Player *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->firstName = argv[1];
    obj->lastName = argv[2];
    obj->address = argv[3];

    return 0;
}

int cb_update_id_player(void  *data,
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

    Player *obj = (Player *) data;

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
