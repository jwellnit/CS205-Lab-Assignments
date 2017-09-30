#include "newplayerscreen.h"

//constructor takes an instance of main screen
NewPlayerScreen::NewPlayerScreen(MainScreen *m){
    go(m);
}

//deconstructor
NewPlayerScreen::~NewPlayerScreen(){
}

//
void NewPlayerScreen::go(MainScreen *m){

    //clear the main screen
    clear();

    //create char arrays for the print out (output) and the input
    char mesg[] = "First Name: ";
    char fn[20];

    initscr();

    //print the output and get the input
    mvprintw(0, 0,"%s", mesg);
    getstr(fn);

    //draw the output and input on the screen
    mvprintw(0, 0, "First Name: %s", fn);
    getch();

    //create char arrays for the print out (output) and the input
    char mesg2[] = "Last Name: ";
    char ln[20];

    initscr();

    //print the output and get the input
    mvprintw(2, 0,"%s", mesg2);
    getstr(ln);

    //draw the output and input on the screen
    mvprintw(2, 0, "Last Name: %s", ln);
    getch();

    //create char arrays for the print out (output) and the input
    char mesg3[] = "Address: ";
    char a[30];

    initscr();

    //print the output and get the input
    mvprintw(4, 0,"%s", mesg3);
    getstr(a);

    //draw the output and input on the screen
    mvprintw(4, 0, "Address: %s", a);
    getch();

    //save the char arrays to strings
    string firstName(fn);
    string lastName(ln);
    string address(a);

    //create and set up a new player object with the inputted info
    Player* player = new Player(m->db);
    player->set_information(firstName, lastName, address);

    //set this player to the current player in main and add it to the player game history
    m->currentPlayer = player;
    m->pgh->add_player(player);

    endwin();
    return; //return to the main tui
}


