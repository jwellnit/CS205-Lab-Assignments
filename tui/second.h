#ifndef SECOND_H
#define SECOND_H

#include "screen.h";

class Second : public Screen {

public:

    //constructors
    Second();
    ~Second();

    //methods
    int begin();
    int get();
    void print();

    //vars
    int cnt;
};

#endif // SECOND_H
