#include "gamehistory.h"


// constructors and destructors
// basic constructor
GameHistory::GameHistory(int pid, DBTool* db)
{
    playerId = pid;
}

// constructor with provided first game
GameHistory::GameHistory(Game *g, int pid, DBTool* db)
{
    playerId = pid;
    history.push_back(g);
}

// destructor
GameHistory::~GameHistory()
{

}

// adds a new game to the history
void GameHistory::add_game(Game *g)
{
    history.push_back(g);
}

Game* GameHistory::get_game(int i)
{
    return history[i];
}
