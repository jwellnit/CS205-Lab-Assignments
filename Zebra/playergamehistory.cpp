#include "playergamehistory.h"

// constructors and destructor
// basic constructor
PlayerGameHistory::PlayerGameHistory(DBTool* db)
{
    database    = db;
    playerTable = "players";
    gameTable   = "games";

    players.resize(0);
    games.resize(0);

    // load in db data
    populate();
}

// constructor with provided first player (DO NOT USE)
PlayerGameHistory::PlayerGameHistory(Player *p, DBTool* db)
{
    database    = db;
    playerTable = "players";
    gameTable   = "games";

    // load in db data
    populate();

    players.push_back(p);

    for (int i = 0; i < p->history->history.size(); i++) {
        games.push_back(p->history->get_game(i));
    }
}

// destructor
PlayerGameHistory::~PlayerGameHistory()
{
    // delete all players and games
    for (int i =0; i < players.size(); i++) {
        delete players[i];
    }

    for (int i =0; i < games.size(); i++) {
        delete games[i];
    }
}

// data setting methods
// add a new player to the list
void PlayerGameHistory::add_player(Player *p)
{
    players.push_back(p);
    cout << players.size() << endl;
}

// add a new game to a provided player
void PlayerGameHistory::add_game(Game *g, Player *p)
{
    // checks if the given player is in the list
    int ind = -1;

    for (int i =0; i < players.size(); i++) {
        if (players[i] == p) {
            ind = i;
        }
    }

    if (ind == -1) {
        cerr << "ERR: Trying to access a player not in the list" << endl;
        return;
    }

    //adds the game to the list and to the player
    players[ind]->play_game(g);
    games.push_back(g);
}

// add a new game to an indexed player
void PlayerGameHistory::add_game(Game *g, int i)
{
    // checks if the given player is in the list
    if (i >= players.size()) {
        cerr << "ERR: Trying to access a player not in the list" << endl;
        return;
    }

    //adds the game to the list and to the player
    players[i]->play_game(g);
    games.push_back(g);
}

// sets the score for an indexed game
void PlayerGameHistory::set_score(int i, int score)
{
    // checks if the given game is in the list
    if (i >= games.size()) {
        cerr << "ERR: Trying to access a game not in the list" << endl;
        return;
    }

    // sets the game score
    games[i]->set_score(score);
}

// set the score for a provided game
void PlayerGameHistory::set_score(Game *g, int score)
{
    // checks if the given game is in the list
    int ind = -1;

    for (int i =0; i < games.size(); i++) {
        if (games[i] == g) {
            ind = i;
        }
    }

    if (ind == -1) {
        cerr << "ERR: Trying to access a game not in the list" << endl;
        return;
    }

    // sets the game score
    games[ind]->set_score(score);

}

// dynamic statistics
// returns the total number of games played
int PlayerGameHistory::num_games_played()
{
    return games.size();
}

// returns the total number of players that have playeed a game
int PlayerGameHistory::num_activce_players()
{
    int count = 0;

    for (int i =0; i < players.size(); i++) {
        if (players[i]->history->history.size() > 0) {
            count++;
        }
    }

    return count;
}

// returns the average number of games played across all players
float PlayerGameHistory::avg_games_per_player()
{
    int total = 0;

    for (int i =0; i < players.size(); i++) {
        total += players[i]->history->history.size();
    }

    float avg;

    if (players.size() != 0) {
        avg = (float)(total/players.size());
    }

    return avg;
}

// returns the highest single score achieved on a game
int PlayerGameHistory::top_game_score()
{
    int topScore = 0;

    for (int i =0; i < games.size(); i++) {
        if (topScore < games[i]->score) {
            topScore = games[i]->score;
        }
    }

    return topScore;
}

// returns the average score across all games
float PlayerGameHistory::avg_score_games()
{
    int total = 0;

    for (int i =0; i < games.size(); i++) {
        total += games[i]->score;
    }

    float avg;

    if (games.size() != 0) {
        avg = (float)(total/games.size());
    }

    return avg;
}

// returns the average score across all games played by a provided player
float PlayerGameHistory::avg_score_player(Player *p)
{
    Player *player = nullptr; // create a temp player var

    // checks if the given player is in the list
    int ind = -1;

    for (int i = 0; i < players.size(); i++) {
        if (players[i] == p) {
            ind = i;
        }
    }

    if (ind == -1) {
        cerr << "ERR: Trying to access a player not in the list" << endl;
        return (float)-1;
    }

    player = players[ind];

    vector<Game*> playerGames = player->history->history;
    int total = 0;

    for (int i = 0; i < playerGames.size(); i++) {
        total += playerGames[i]->score;
    }

    float avg;

    if (playerGames.size() != 0) {
        avg = (float)(total/playerGames.size());
    }

    return avg;
}

// returns the average score across all games played by an indexed player
float PlayerGameHistory::avg_score_player(int i)
{
    Player *player = nullptr; // create a temp player var

    // checks if the given player is in the list
    if (i >= players.size()) {
        cerr << "ERR: Trying to access a player not in the list" << endl;
        return (float)-1;
    }

    player = players[i];

    vector<Game*> playerGames = player->history->history;
    int total = 0;

    for (int i =0; i < playerGames.size(); i++) {
        total += playerGames[i]->score;
    }

    float avg;

    if (playerGames.size() != 0) {
        avg = (float)(total/playerGames.size());
    }

    return avg;
}


// database methods
// loads in the players and games from the db
void PlayerGameHistory::populate()
{
    // creates dummy player and game to get the row counts from those tables
    Player dummyP(database);
    dummyP.id = -1;
    Game dummyG(database);
    dummyG.id = -1;

    id_game = 0;
    id_player = 0;

    // loads in all players
    for (int i = 0; i < player_row_cnt; i++) {
        Player* p = new Player(database);
        p->select_id(i);
        add_player(p);
    }

    // loads in all games and assigns them to their players
    for (int i = 0; i < game_row_cnt; i++) {
        Game* g = new Game(database);
        g->select_id(i);
        int pid = g->playerId;
        for (int j = 0; j < players.size(); j++) {
            if (players[j]->id == pid) {
                add_game(g, players[j]);
                break;
            }
        }
    }
}

// returns the score of a non null game
int PlayerGameHistory::get_score(Game *g){
    if(g != nullptr){
        return g->score;
    }else{
        return -1;
    }
}
