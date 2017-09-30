#include "screen.h"

Screen::Screen(){
}

Screen::~Screen(){
}

void Screen::set_up(){

    initscr();

    curs_set(0);

    cbreak();

    noecho();

    keypad(stdscr, TRUE);

    continue_looping = true;
}

//// a function for drawing the current screen
//void Screen::draw_screen(int cnt) {

//    // print the state of the value object
//    mvprintw(2, 4, "Current Value : ");
//    std::string display = std::to_string(cnt);
//    mvprintw(2, 21, display.c_str());

//    // print the instructions for manipulating the Value object
//    mvprintw(5, 4, "Up Arrow    : increments value");
//    mvprintw(6, 4, "Down Arrow  : decrements value");
//    mvprintw(7, 4, "Left Arrow  : resets value to zero");
//    mvprintw(8, 4, "Right Arrow : exits program");
//}


