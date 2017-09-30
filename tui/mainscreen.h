#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "screen.h"
#include "../Zebra/game.h"
#include "../Zebra/gamehistory.h"
#include "../Zebra/player.h"
#include "../Zebra/playergamehistory.h"
#include "displaystats.h"
#include "displaytopthreegames.h"
#include "displaytopthreeplayers.h"
#include "newplayerscreen.h"
#include "selectexistingplayer.h"
#include "displaystats.h"
#include "robotstui.h"
#include "wormtui.h"

//forward class declarations
class DisplayStats;
class DisplayTopThreeGames;
class DisplayTopThreePlayers;
class NewPlayerScreen;
class SelectExistingPlayer;
class RobotsTui;
class WormTui;

class MainScreen : public Screen {
public:

    //constructors
    MainScreen();
    ~MainScreen();

    //objects
    Player*             currentPlayer;
    PlayerGameHistory*  pgh;
    DBTool*             db;

    Game                currentGame();
    Player*             get_player();
    PlayerGameHistory*  get_player_game_history();

    //methods
    int keys();
    int get_num_active_players();

    void draw();
    void create_new_player();
    void select_existing_player();
    void display_top_three_players();
    void display_top_three_games_played();
    void display_calculated_statistics();
    void play_robots();
    void play_worm();
    void exit_program();
    void set_game_score(int i);
};

#endif // MAINSCREEN_H
