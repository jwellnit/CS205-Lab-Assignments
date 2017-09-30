#include "displaystats.h"

//main constructor
DisplayStats::DisplayStats(MainScreen *m)
{
    clear();
    main = m;
    p    = main->get_player();
    ph   = main->get_player_game_history();

    // get the sats if ph exists
    if (ph != nullptr) {

        numGamesPlayed    = ph->num_games_played();

        numActivcePlayers = ph->num_activce_players();

        avgGamesPerPlayer = ph->avg_games_per_player();

        topGameScore      = ph->top_game_score();

        avgScoreGames     = ph->avg_score_games();

        // get stats for current player if there is one
        if (p != nullptr) {
            avgScorePlayer = ph->avg_score_player(p);
        }
    }

    begin();
}

// destructor
DisplayStats::~DisplayStats()
{
    clear();
}

// runs the screen
void DisplayStats::begin()
{
    continue_looping = true;

    //print the screen
    print();

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        if (ch == 'r') {
            continue_looping = false;
        }

        print();

    } while(continue_looping);

    refresh();

    //cleanup the window and return control to MainScreen
    endwin();
}

//print out of the variables in the tui
void DisplayStats::print()
{
    mvprintw(0, 10, "STATISTICS");

    if (ph != nullptr) {
        mvprintw(5, 10, "Number of Games Played: ");
        mvprintw(5, 34, "%d",  numGamesPlayed);

        mvprintw(6, 10, "Number of Active Players: ");
        mvprintw(6, 36, "%d", numActivcePlayers);

        mvprintw(7, 10, "Average Games per Player: ");
        mvprintw(7, 36, "%f", avgGamesPerPlayer);

        mvprintw(8, 10, "Top Game Score: ");
        mvprintw(8, 26, "%d", topGameScore);

        mvprintw(9, 10, "Average Score Across All Games: ");
        mvprintw(9, 41, "%f", avgScoreGames);

        if (p != nullptr) {
            mvprintw(10, 10, "Average Score of Current Player: ");
            mvprintw(10, 43, "%f", avgScorePlayer);
        }
    } else {
        mvprintw(5, 10, "Not Enough Information");
    }

    mvprintw(13, 10, "Press 'r' to return");
}
