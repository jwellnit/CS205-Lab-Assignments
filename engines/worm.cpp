#include "worm.h"

using namespace std;

//base constructor
Worm::Worm(int rows, int cols): Engine(rows, cols){
    xShift = 0;
    yShift = 0;
    tailSize = 0;
    tailCue = 0;
}

//base constructor
Worm::Worm(): Engine(50, 25){
    xShift = 0;
    yShift = 0;
    tailSize = 0;
    tailCue = 0;
}

//deconstructor
Worm::~Worm() {
}

// copy assignment
void Worm::operator = (Worm &obj) {
    rows = obj.rows;
    cols = obj.cols;

    // allocation
    gameBoard = obj.gameBoard;

    //initializes all variables
    wH_x = obj.wH_x;
    wH_y = obj.wH_y;

    f_x = obj.f_x;
    f_y = obj.f_y;

    tailSize = obj.tailSize;

    for(int i = 0; i < tailSize; i ++){
        tailCoordinateX[i] = obj.tailCoordinateX[i];
        tailCoordinateY[i] = obj.tailCoordinateY[i];
    }

    wormHead = obj.wormHead;

    food = obj.food;

    xShift = obj.xShift;
    yShift = obj.yShift;
}

//place the food on the board. called when the board is created and everytime the worm has hit food
void Worm::place_food(){

    //generate a random food particle
    food = rand() % 9 + 1;
    string s = to_string(food);
    char f = s[0];

    //generate random x and y coordinates for the food particle
    f_x = rand() % (cols-2) + 1;
    f_y = rand() % (rows-2) + 1;

    //place the food particle
    if(examine_space(f_x, f_y) == ' '){ //make sure the space is empty
        set_space(f_x, f_y, f);

    }else{ //otherwise retry
        place_food();
    }
}

//check if the worm has landed on food
void Worm::check_hit(){
    if(examine_space(wH_x, wH_y) == examine_space(f_x, f_y)){
        hit_food();
    }else{
        return;
    }
}

//goes here when the worm hits a particle of food
void Worm::hit_food(){

    //remove old food
    set_space(f_x, f_y, ' ');

    //update point total

    //add a link to the snake, the value of the food particles
    for(int i = 0; i < food; i++){
        add_link();
    }

    //generate and place new food
    place_food();
}

//add a link to the worm's tail
void Worm::add_link(){

    tailSize ++; //update the tail size

    tailCue ++; //update the tail cue
}

//player action methods
void Worm::left_key(){
    yShift = 1;
}

void Worm::right_key(){
    yShift = - 1;
}

void Worm::up_key(){
    xShift = - 1;
}

void Worm::down_key(){
    xShift = 1;
}

//update worm head and tail movement wise
void Worm::update_board(){

    //remove the head
    set_space(wH_x, wH_y, ' ');

    //move 'o' to old location of head
    set_space(wH_x, wH_y, 'o');

    //update the head coordinates
    wH_x = wH_x + xShift;
    wH_y = wH_y + yShift;

    //move the head
    set_space(wH_x, wH_y, wormHead);

    if(tailCue == 0){
        //remove the last tail link
        set_space(tailCoordinateX[tailSize-1], tailCoordinateY[tailSize-1], ' ');

    }else{
        tailCue --;
    }

    //update the tailCoordinate arrays
    tailCoordinateX[tailSize] = wH_x;
    tailCoordinateY[tailSize] = wH_y;

    //update the tailCoordinate array
    for(int i = tailSize; i > 1; i --){
        tailCoordinateX[i - 1] = tailCoordinateX[i - 2];
        tailCoordinateY[i - 1] = tailCoordinateY[i - 2];
    }
    tailCoordinateX[0] = wH_x;
    tailCoordinateY[0] = wH_y;
}

//clear the x and y shift
void Worm::clear_shift(){
    xShift = 0;
    yShift = 0;
}

//check if the worm's next move will end the game
bool Worm::check_move(){
    if(examine_space(wH_x + xShift, wH_y + yShift) == 'o'){
        return false;
    }else if(examine_space(wH_x + xShift, wH_y + yShift) == 'X'){
        return false;
    }else{
        return true;
    }
}

//draw the initial board
void Worm::draw(int rows, int cols){

    //construct the game array - an empty array of chars
    for(int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){

            set_space(i, j, ' ');

            set_space(0, j, 'X'); //border
            set_space(cols-2, j, 'X'); //border
        }
        set_space(i, 0, 'X'); //border
        set_space(i,rows-2, 'X'); //border
    }

    //construct the worm head
    wormHead = '@';

    //place worm head in a set location
    wH_x = 15;
    wH_y = 15;
    set_space(wH_x, wH_y, wormHead);

    //create the food
    food = rand() % 10;

    //place the food
    place_food();

    tailSize = 0;

    //create worm body
    for(int i = 0; i < 3; i++){ //tail begins with 2 links
        add_link();
        update_board();
    }
}

