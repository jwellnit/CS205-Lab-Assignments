#include "log.h"

using namespace std;

// In the default constructor the file handler is opened.
Log::Log(std::string fileName) {
    open_app(fileName);
}

// In the destructor the file handler is closed.
Log::~Log() {
    fh.close();
}

// base constructor
Log::Log() {
    SHOW_WHERE;
}

// copy constructor
Log::Log(Log &obj) {
    currentFile = obj.currentFile;
    isOpen = obj.isOpen;
    flush();
    close();
    open_app(currentFile);
    SHOW_WHERE;
}

// copy assignment
void Log::operator = (Log &obj) {
    currentFile = obj.currentFile;
    isOpen = obj.isOpen;
    flush();
    close();
    open_app(currentFile);
}


// opens a file to be appended by the logger
void Log::open_app(std::string fileName) {
    try {
        currentFile = fileName;
        fh.open(fileName, std::ofstream::out | std::ofstream::app );
        isOpen = fh.is_open();
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

// opens an empty file for the logger to write to
void Log::open_empty(std::string fileName) {
    try {
        currentFile = fileName;
        fh.open("./" + fileName, std::ofstream::out | std::ofstream::trunc );
        isOpen = fh.is_open();
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

// closes the currrent file in the file handler
void Log::close() {
    try {
        fh.close();
        currentFile = "";
        isOpen = fh.is_open();
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

// closes the currrent file in the file handler
void Log::flush() {
    try {
        fh.flush();
    } catch (const std::exception& e) {
        cout << "An exception has occurred: " << e.what() << endl;
    }
}

// Returns the current value of isOpen, which comes from the fileHandler
// method of the same name.
bool Log::get_state() {
    return isOpen;
}

// Returns the name of the currently open file
string Log::get_filename() {
    return currentFile;
}

// The overloaded operator will process the incoming string, then return
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (std::string str) {

    fh << str;

    return *this;
}

// The overloaded operator will convert the int into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (char input) {

    fh << input ;

    return *this;
}


// The overloaded operator will convert the int into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (int input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the long into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (long input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the long long into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (long long input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the unsigned into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (unsigned input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the unsigned long into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (unsigned long input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the unsigned long long into a
// string and then pass itself as a reference.  This allows chaining of
// multiple filehandler operations.
Log& Log::operator << (unsigned long long input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the unsigned float into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (float input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the double into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (double input) {

    fh << std::to_string( input );

    return *this;
}

// The overloaded operator will convert the long double into a string and then pass
// itself as a reference.  This allows chaining of multiple filehandler
// operations.
Log& Log::operator << (long double input) {

    fh << std::to_string( input );

    return *this;
}
