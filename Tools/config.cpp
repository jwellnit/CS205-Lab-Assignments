#include "config.h"

using namespace std;

//constructor/base constructor
Config::Config(string name){
    load_file(name);
}

//deconstructor
Config::~Config() {
}

//base constructor
Config::Config(){
    SHOW_WHERE;
}

// copy constructor
Config::Config(Config &obj){

    myMap    = obj.myMap;
    fileName = obj.fileName;

    SHOW_WHERE;
}

// copy assignment
void Config::operator=(Config &obj) {
    myMap    = obj.myMap;
    fileName = obj.fileName;
}

//load/reload the file
void Config::load_file(string iname) {

    fileName = iname;

    //try to open the file name you provided
    try{
        ifstream ist{iname};

        //if the file opens properly
        if(ist){
            std::string key   = "";
            std::string value = "";
            std::string line  = "";

            //break the file up into lines
            while (std::getline(ist, line)){

                std::stringstream st(line);

                //break the lines up into key and value
                while(st.good()){
                    getline(st, line,' ');
                    key = line;
                    getline(st, line,' ');
                    value = line;

                    //add the key and value to the map
                    myMap[key] = value;
                }
            }

            //if the file does not open properly
        }else{
            cout << ("can't open input file") << endl;
        }
    }catch(const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

//rename the file
void Config::rename_file(string newName){

    try{
        //get old and new file names
        string oldName = fileName;

        //rename file
        int u = rename(oldName.c_str(), newName.c_str());

        //update fileName global variable
        fileName = newName;

        //check if the file was properly renamed
        if (u == 0){
            cout << "File is renamed " << endl;
        }else{
            cout << "Error renaming file" << endl;
        }
    }catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

//change the file path
void Config::change_file_path(string filePath){

    try{
        //get the new file path
        string oldName = fileName;
        string newName = filePath + oldName;

        //rename the file with the new file path
        int u = rename(oldName.c_str(), newName.c_str());

        //check to make sure the file was renamed properly
        if (u == 0){
            cout << "File location changed " << endl;
        }else{
            cout << "Error changing file path" << endl;
        }
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

//reload the file-clears the map and then redirects to LoadFile
void Config::reload_file(string name){
    myMap.clear();
    load_file(name);
}

//writes the map to a new file
void Config::write_file(string oname){

    ofstream ost{oname};
    string   mapString = "";

    //get map values
    for (std::map<string,string>::iterator
         it=myMap.begin(); it!=myMap.end(); ++it){

        mapString += it->first + " " + it->second + "\n";
    }

    try{
        ost << mapString;

        fileName = oname;

        if(!ost){
            cout << "can't do it" << endl;
        }
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

//set
void Config::add_to_map(string key, string value){
    myMap[key]=value;
}

//get
string Config::get_from_map(string key){
    return myMap[key];
}

// returns the nam of the current woking file
string Config::get_filename() {
    return fileName;
}


