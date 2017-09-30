#include "robotstui.h"

//forward method declarations
int  get();
int  begin();
void print();

//constructor
RobotsTui::RobotsTui(int rows, int cols, int startEnemies, MainScreen *main){

    //intialize variables
    numEnemies       = startEnemies;
    continue_looping = true;
    this->main       = main;

    Robots* temp =  new Robots(rows, cols);

    r = *temp;
    r.clear_board();
    r.populate_board(numEnemies);

    begin();
    print();
}

//constructor
RobotsTui::RobotsTui(MainScreen *main){

    //initialize variables
    numEnemies       = 10;
    this->main       = main;
    continue_looping = true;

    Robots* temp =  new Robots(22, 60);

    r = *temp;
    r.clear_board();
    r.populate_board(numEnemies);

    begin();
    print();
}

//deconstructor
RobotsTui::~RobotsTui(){
}

void RobotsTui::begin(){
    //print the starting board
    print();

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        r.move(ch);

        print();

        continue_looping = r.get_status();

    } while(continue_looping);

    play_again();
}

//print out the tui board
void RobotsTui::print(){

    int rows = r.get_rows();
    int cols = r.get_cols();

    //print the gameboard
    for (int i = 1; i < cols + 1; i++) {
        for (int j = 1; j < rows + 1; j++) {
            char tmp = r.examine_space(i-1, j-1);
            mvprintw(j, i, &tmp);
        }
    }

    //print a border around the playable screen
    for (int i = 0; i < cols + 2; i++) {
        mvprintw(0, i, "X");
        mvprintw(rows + 1, i, "X");
    }

    for (int i = 1; i < rows + 1; i++) {
        mvprintw(i, 0, "X");
        mvprintw(i, cols + 1, "X");
    }

    //print and explanation of the directions and controls
    mvprintw(0, cols + 4, "Directions :");
    mvprintw(2, cols + 4, "y k u");
    mvprintw(3, cols + 4, " \\|/ ");
    mvprintw(4, cols + 4, "h- -l");
    mvprintw(5, cols + 4, " /|\\ ");
    mvprintw(6, cols + 4, "b j n");

    mvprintw(8, cols + 4, "Controls :");
    mvprintw(10, cols + 4, "w:  wait for end");
    mvprintw(11, cols + 4, ">:  wait while safe");
    mvprintw(12, cols + 4, ".:  skip turn");
    mvprintw(13, cols + 4, "t:  teleport");
    mvprintw(14, cols + 4, "q:  quit");
    mvprintw(15, cols + 4, "^L: redraw screen");

    mvprintw(17, cols + 4, "Legend :");
    mvprintw(18, cols + 4, "r: robot");
    mvprintw(19, cols + 4, "*: trash pile");
    mvprintw(20, cols + 4, "h: player");

    //prints the score
    //std::string score = std::to_string(r.score);
    //mvprintw(22, cols + 4, "Score : ");
    //mvprintw(22, cols + 11, score.c_str());
}

//replay option set up and drawn
void RobotsTui::play_again()
{
    int rows = r.get_rows();
    int cols = r.get_cols();

    clear(); // clear the screen

    // ask ifthe player would like to continue
    mvprintw((rows + 12)/2, (cols + 2)/2, "Game Over");
    mvprintw((rows + 12)/2 + 1, (cols + 2)/2, "Would you like to play again?");
    mvprintw((rows + 12)/2 + 3, (cols + 2)/2, "y: yes");
    mvprintw((rows + 12)/2 + 4, (cols + 2)/2, "n: no");

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
            answer = true;
            answered = true;
            break;
        case 'n':
            answered = true;
            break;
        }

    } while(!answered);

    if (answer) {

        //play again
        r.clear_board();
        r.populate_board(numEnemies);

        continue_looping = true;

        begin();

    } else {

        //cleanup the window and return control to MainScreen
        endwin();
        return;

        std::cout << "exiting main\n";
    }

}
