#include "mainscreen.h"

MainScreen::MainScreen(){
    db = new DBTool("database");
    pgh = new PlayerGameHistory(db);
    currentPlayer = nullptr;
    set_up();
    draw();
    continue_looping = true;
    keys();

}

MainScreen::~MainScreen(){
    delete pgh;
    delete db;
}

//draw out the initial main screen with all the selections
void MainScreen::draw(){

    mvprintw(2, 4, "(a) Create a New Player");
    mvprintw(3, 4, "(b) Select an Existing Player");
    mvprintw(4, 4, "(c) Display Top 3 Players");
    mvprintw(5, 4, "(d) Display Top 3 Games Played");
    mvprintw(6, 4, "(e) Display Calculated Statistics");
    mvprintw(7, 4, "(f) Play Robots");
    mvprintw(8, 4, "(g) Play Worm");
    mvprintw(9, 4, "(h) Exit Program");
}

//assign actions to the keys
int MainScreen::keys(){
    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {

        case 'a':
            create_new_player();
            break;
        case 'b':
            select_existing_player();
            break;
        case 'c':
            display_top_three_players();
            break;
        case 'd':
            display_top_three_games_played();
            break;
        case 'e':
            display_calculated_statistics();
            break;
        case 'f':
            play_robots();
            break;
        case 'g':
            play_worm();
            break;
        case 'h':
            exit_program();
            break;
        }

        draw();

    } while(continue_looping);

    //cleanup the window and return control to bash
    endwin();

    std::cout << "exiting main\n";
    return 0;
}

//create an instance of the new player screen, allow it to perform its function
void MainScreen::create_new_player(){
    NewPlayerScreen nps(this);
    clear();
}

//create an instance of the select existing player screen, allow it to perform its function
void MainScreen::select_existing_player(){
   SelectExistingPlayer sep(this);
   clear();
}

//create an instance of the display top three players screen, allow it to perform its function
void MainScreen::display_top_three_players(){
   DisplayTopThreePlayers dttp(this);
   clear();
}

//create an instance of the display top three games screen, allow it to perform its function
void MainScreen::display_top_three_games_played(){
    DisplayTopThreeGames displayTopThreeGames(this);
    clear();
}

//create an instance of the display calculated statistics screen, allow it to perform its function
void MainScreen::display_calculated_statistics(){
    DisplayStats ds(this);
    clear();
}

//create a new game and create and run the robots tui, save the score
void MainScreen::play_robots(){

    if(currentPlayer != nullptr){ //make sure the current player exists

        Game *g = new Game(currentPlayer, db); //create a new game

        RobotsTui robotsTui (20, 60, 20, this); //play robots

        g->set_score(robotsTui.r.score); //save the score to the game object
        pgh->add_game(g, currentPlayer); //add the game and player to the player game history

        clear();
    }else{

    }
}

//create a new game and create and run the worm tui, save the score
void MainScreen::play_worm(){

    if(currentPlayer != nullptr){

        Game *g = new Game(currentPlayer, db); //create a new game

        WormTui wormTui (50, 25, this); //play worm

        g->set_score(wormTui.score); //save the score to the game object
        pgh->add_game(g, currentPlayer); //add the game and player to the player game history

        clear();
    }else{

    }
}

//exit the tui
void MainScreen::exit_program(){
    continue_looping = false;
}

//getter for the current player
Player* MainScreen::get_player(){
    return currentPlayer;
}

//getter for the player game history object
PlayerGameHistory* MainScreen::get_player_game_history(){
    return pgh;
}

//getter for the number of players
int MainScreen::get_num_active_players(){
    return pgh->players.size();
}
