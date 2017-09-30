#ifndef ENGINE_H
#define ENGINE_H

#include "../Tools/macro.h"
using namespace std;

class Engine
{

protected:
    int rows;
    int cols;
    char ** gameBoard;

public:
    //constructors
    Engine(int rows, int cols);
    Engine();
    ~Engine();

    //array manipulation
    char examine_space(int x, int y);
    void set_space(int x, int y, char sym);
    static int id_cnt;
    int id;

    void print_board();
    int get_cols();
    int get_rows();
};

#endif // ENGINE_H
