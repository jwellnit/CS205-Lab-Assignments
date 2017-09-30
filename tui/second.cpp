#include "second.h"

int get();
int begin();
void print();

Second::Second(){
    cnt = 0;
    set_up();
    begin();
    print();
}

Second::~Second(){
}

int Second::begin(){
    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case KEY_DOWN:
            cnt--;
            break;
        case KEY_UP:
            cnt++;
            break;
        case KEY_LEFT:
            cnt = 0;
            break;
        case KEY_RIGHT:
            continue_looping = false;
            break;
        }

        print();

    } while(continue_looping);

    //cleanup the window and return control to bash
    endwin();

    std::cout << "exiting main\n";
    return 0;
}

void Second::print(){

    // print the state of the value object
    mvprintw(2, 4, "Current Value : ");
    std::string display = std::to_string(cnt);
    mvprintw(2, 21, display.c_str());

    // print the instructions for manipulating the Value object
    mvprintw(5, 4, "Up Arrow    : increments value");
    mvprintw(6, 4, "Down Arrow  : decrements value");
    mvprintw(7, 4, "Left Arrow  : resets value to zero");
    mvprintw(8, 4, "Right Arrow : exits program");

}

int Second::get() {
    return cnt;
}
