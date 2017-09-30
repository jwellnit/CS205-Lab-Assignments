#include "displaytopthreegames.h"

//constructor taking an instance of the main screen class
DisplayTopThreeGames::DisplayTopThreeGames(MainScreen *m)
{
    clear();

    main = m;
    ph   = main->get_player_game_history();
    g    = ph->games;

    // loop through to find the top players
    if (g.size() >= 3) {

        g1 = g[0];

        int g1i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g1)) {

                g1  = g[i];
                g1i = i;
            }
        }

        g[g1i] = nullptr;

        g.shrink_to_fit();

        g2 = g[0];

        int g2i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g2)) {

                g2  = g[i];
                g2i = i;
            }
        }

        g[g2i] = nullptr;

        g.shrink_to_fit();

        g3 = g[0];

        int g3i = 0;

        for (int i = 0; i < g.size(); i++) {
            if (ph->get_score(g[i]) >= ph->get_score(g3)) {

                g3  = g[i];
                g3i = i;
            }
        }

        g[g3i] = nullptr;

        g.shrink_to_fit();

        g = ph->games;
    }

    begin();
}

//deconstructor
DisplayTopThreeGames::~DisplayTopThreeGames()
{
    clear();
}

// runs the screen
void DisplayTopThreeGames::begin()
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

//print out the top three games to the tui
void DisplayTopThreeGames::print()
{
    mvprintw(0, 10, "TOP THREE GAMES");

    if (g.size() >= 3) {
        mvprintw(5, 10, "1st: ");
        mvprintw(5, 16, "%s", g1->name + ", " + to_string(g1->score));

        mvprintw(7, 10, "2st: ");
        mvprintw(5, 16, "%s", g2->name + ", " + to_string(g2->score));

        mvprintw(9, 10, "3rd: ");
        mvprintw(5, 16, "%s", g3->name + ", " + to_string(g3->score));
    } else {
        mvprintw(5, 10, "Not Enough Information");
    }

    mvprintw(13, 10, "Press 'r' to return");
}
