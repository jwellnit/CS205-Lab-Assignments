#ifndef BASECLASS_H
#define BASECLASS_H

#include "macro.h"

class BaseClass
{
    // Class that contains a counting/id mechanism for classes to inherit from
public:
    BaseClass();

    static int id_cnt;

    int id;
};

#endif // BASECLASS_H
