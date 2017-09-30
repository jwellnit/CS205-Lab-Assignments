#include "engine.h"

// Initialize the static variable that tracks
// number of objects created.
int Engine::id_cnt = 0;

Engine::Engine(int rows, int cols){

    // Uniquely identify the object.
    id = id_cnt;

    // Increment the created object count.
    id_cnt++;

    //SHOW_WHERE
    this->rows = rows;
    this->cols = cols;

    // allocation
    gameBoard = new char*[cols];
    for(int i = 0; i < cols; i++){
        //cerr << i << endl;
        gameBoard[i] = new char[rows];
    }

    // initialization
    for(int j = 0; j < rows; j++)
        for(int i = 0; i < cols; i++)
            gameBoard[i][j] = ' ';
}

Engine::Engine(){

    // Uniquely identify the object.
    id = id_cnt;

    // Increment the created object count.
    id_cnt++;

    //SHOW_WHERE
    this->rows = 5;
    this->cols = 5;

    // allocation
    gameBoard = new char*[cols];
    for(int i = 0; i < cols; i++){
        //cerr << i << endl;
        gameBoard[i] = new char[rows];
    }

    // initialization
    for(int j = 0; j < rows; j++)
        for(int i = 0; i < cols; i++)
            gameBoard[i][j] = ' ';
}

Engine::~Engine()
{
    //    for(int i = cols-1; i >= 0; i--)
    //        for(int j = rows-1; j >= 0; j--)
    //            delete gameBoard[i][j];
    //SHOW_WHERE
    for(int i = cols-1; i >= 0; i--) {
        //cerr << i << endl;
        //cerr << gameBoard[i] << endl;
        delete gameBoard[i];
    }
    //cerr << gameBoard << endl;
    delete gameBoard;
}

char Engine::examine_space(int x, int y)
{
    //SHOW_WHERE
//    cout << "a" << endl;
    if (x < 0 || x >= cols || y < 0 || y >= rows) {
//        cout << "z" << endl;
        throw "Array out of bounds";
    }
//    cout << "b" << endl;
//    cout << gameBoard[x][y] << endl;
    return gameBoard[x][y];
}

void Engine::set_space(int x, int y, char sym)
{
    //SHOW_WHERE
    if (x < 0 || x >= cols || y < 0 || y >= rows) {
        throw "Array out of bounds";
        return;
    }

    gameBoard[x][y] = sym;
}

void Engine::print_board(){
    for (int i = 0; i < cols; i ++){
        for(int j = 0; j < rows; j ++){
            cout << gameBoard[i][j];
        }
        cout << "\n";
    }
}

int Engine::get_cols()
{
    return cols;
}

int Engine::get_rows()
{
    return rows;
}
