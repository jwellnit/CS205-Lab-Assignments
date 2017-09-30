#include "displaytopthreeplayers.h"

//constructor taking an instance of the main screen
DisplayTopThreePlayers::DisplayTopThreePlayers(MainScreen *m)
{
    clear();

    main = m;
    ph   = main->get_player_game_history();
    p    = ph->players;

    // loop through to find the top games
    if (p.size() >= 3) {

        p1 = p[0];

        int p1i = 0;

        for (int i = 0; i < p.size(); i++) {
            if (ph->avg_score_player(p[i]) >= ph->avg_score_player(p1)) {

                p1  = p[i];
                p1i = i;
            }
        }

        p[p1i] = nullptr;

        p.shrink_to_fit();

        p2 = p[0];

        int p2i = 0;

        for (int i = 0; i < p.size(); i++) {
            if (ph->avg_score_player(p[i]) >= ph->avg_score_player(p2)) {

                p2  = p[i];
                p2i = i;
            }
        }

        p[p2i] = nullptr;

        p.shrink_to_fit();

        p3 = p[0];

        int p3i = 0;

        for (int i = 0; i < p.size(); i++) {
            if (ph->avg_score_player(p[i]) >= ph->avg_score_player(p3)) {

                p3  = p[i];
                p3i = i;
            }
        }

        p[p3i] = nullptr;

        p.shrink_to_fit();

        p = ph->players;
    }

    begin();
}

//deconstructor
DisplayTopThreePlayers::~DisplayTopThreePlayers()
{
    clear();
}

// runs the screen
void DisplayTopThreePlayers::begin()
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

//print out the top three players to the tui
void DisplayTopThreePlayers::print()
{
    mvprintw(0, 10, "TOP THREE PLAYERS");

    if (p.size() >= 3) {
        mvprintw(5, 10, "1st: ");
        string name1 = p1->firstName + ", " + p1->lastName;
        mvprintw(5, 16, "%s", name1.c_str());

        mvprintw(7, 10, "2st: ");
        mvprintw(5, 16, "%s", p2->firstName + p2->lastName);

        mvprintw(9, 10, "3rd: ");
        mvprintw(5, 16, "%s", p3->firstName + p3->lastName);
    } else {
        mvprintw(5, 10, "Not Enough Information");
    }

    mvprintw(13, 10, "Press 'r' to return");
}
