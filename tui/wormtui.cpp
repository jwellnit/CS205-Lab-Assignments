#include "wormtui.h"

int get();
int begin();
void print();

//constructor
WormTui::WormTui(int rows, int cols, MainScreen *m){

    //initalize variables
    main             = m;
    continue_looping = true;

    //create a copy of worm
    Worm* temp =  new Worm(rows, cols);
    w          = *temp;

    w.draw(rows, cols);

    begin();
    print();
}

//constructor
WormTui::WormTui(){

    //initialize variables
    continue_looping = true;

    //create a copy of worm
    Worm* temp =  new Worm(50, 25);
    w          = *temp;

    w.draw(50, 25);

    begin();
    print();
}

//deconstructor
WormTui::~WormTui(){
}


//game sequence using ncurses interface
void WormTui::begin(){

    continue_looping = true;

    //print the starting board
    print();

    do {

        // draw the new screen
        refresh();

        w.check_hit();

        // obtain character from keyboard
        int ch = getch();

        w.clear_shift();

        // operate based on input character
        move(ch);

        w.update_board();

        print();

    } while(continue_looping);

    refresh();

    play_again();
}

void WormTui::print(){

    mvprintw(0, 1, "Worm");

    int rows = 25;
    int cols = 50;

    //print the gameboard
    for (int i = 1; i < cols + 1 ; i++) {
        for (int j = 1; j < rows  + 1; j++) {

            char tmp = w.examine_space(j - 1, i - 1);
            mvprintw(j, i, &tmp);

        }
    }
}

//set up the key presses
void WormTui::move(int ch){

    switch (ch) {
    case KEY_DOWN:
        w.down_key();
        continue_looping = w.check_move();
        break;
    case KEY_UP:
        w.up_key();
        continue_looping = w.check_move();
        break;
    case KEY_RIGHT:
        w.left_key();
        continue_looping = w.check_move();
        break;
    case KEY_LEFT:
        w.right_key();
        continue_looping = w.check_move();
        break;
    case 'e':
        continue_looping = false;
        break;
    }
}

//replay option
void WormTui::play_again(){

    score = w.tailSize; //set a score variable

    int rows = 50;
    int cols = 25;

    clear(); // clear the screen

    // ask ifthe player would like to continue
    mvprintw(2,2, "Game Over");
    mvprintw(3,2, "Would you like to play again?");
    mvprintw(4,2, "y: yes");
    mvprintw(5,2, "n: no");

    bool answered = false;
    bool answer   = false;

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case 'y':

            answer   = true;
            answered = true;

            break;

        case 'n':

            answered = true;
            break;
        }

    } while(!answered);

    if (answer) {

        //play again
        w.draw(50,25);
        continue_looping = true;

        begin();

    } else {

        //cleanup the window and return control to bash
        endwin();
        return;

        std::cout << "exiting main\n";
    }

}



