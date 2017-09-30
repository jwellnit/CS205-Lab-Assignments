#ifndef LOG_H
#define LOG_H

// The header file for the minimal Log class.
#include "macro.h"
#include "baseclass.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Log : public BaseClass
{

public:
    // This class handles a log file that can be printed to at runtime.

    Log(std::string fileName);  // default constructor
    ~Log(); // destructor

    // basic constructors
    Log();                      // base constructor
    Log(Log &obj);              // copy constructor
    void operator=(Log &obj);   // copy assignment

    //methods for open
    void open_app(string fileName);
    void open_empty(std::string fileName);

    //closing and flushing file
    void close();
    void flush();

    bool get_state(); // returns a bool indicating whether a file is currently open
    string get_filename(); // returns the name of the currently open file

    // overloaded handler operator
    Log& operator<<(const std::string str);
    Log& operator<<(const char input);
    Log& operator<<(const int input);
    Log& operator<<(const long input);
    Log& operator<<(const long long input);
    Log& operator<<(const unsigned input);
    Log& operator<<(const unsigned long input);
    Log& operator<<(const unsigned long long input);
    Log& operator<<(const float input);
    Log& operator<<(const double input);
    Log& operator<<(const long double input);

private:


    std::ofstream fh; // the file handler
    std::string currentFile; // the name of the current file
    bool isOpen; // a bool that represents the state of the log
};

#endif // LOG_H
