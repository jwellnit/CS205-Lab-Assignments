#ifndef CONFIG_H
#define CONFIG_H

// The header file for the minimal Config class.
#include "macro.h"
#include "baseclass.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <stdio.h>

using namespace std;

class Config : public BaseClass
{
    // This class represents a configuration mechanism for reading and writing
    // values to a file, as well as retrieving, changing, and adding them at
    // runtime.
public:

    Config(string name);
    ~Config();

    // basic constructors
    Config();                       // base constructor
    Config(Config &obj);            // copy constructor
    void operator=(Config &obj);    // copy assignment

    // file handling methods
    void load_file(string iname);
    void write_file(string oname);
    void reload_file(string name);
    void rename_file(string newName);
    void change_file_path(string filePath);

    // map sets and retrievals
    void    add_to_map(string key, string value);
    string  get_from_map(string key);

    // config information retrieval
    string get_filename();

    map<string,string> myMap; // a map that stores config values at runtime
    string             fileName; // the name of the file the config is currntly reading


};

#endif // CONFIG_H
