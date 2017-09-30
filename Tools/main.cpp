#include <iostream>
#include "log.h"
#include "config.h"

using namespace std;

// Object of type Log globally instantiated.
Log err_log("./errTest.txt");
int testInt = 1;
long testLong = 2;
long long testLongLong = 3;
unsigned testUnsigned = 4;
unsigned long testUnsignedLong = 5;
unsigned long long testUnsignedLongLong = 6;
float testFloat = 7.0;
double testDouble = 8.0;
long double testLongDouble = 9.0;

Config config;

int main(int argc, char *argv[])
{
    // Here the first err_log << string will be evaluated,
    // returning err_log, so the next err_log << can be evaluated.
    err_log << "test" << 2 << 2.44 << "test";

    err_log.flush();
    err_log.close();

    err_log.open_empty("./errTest.txt");
    err_log << testInt << testLong << testLongLong << testUnsigned
            << testUnsignedLong;
    err_log << testUnsignedLongLong << testFloat << testDouble
            << testLongDouble << "\n";

    err_log.flush();
    err_log.close();

    err_log.open_app("./errTest.txt");
    err_log << "This is the end of the test file.";

    err_log.flush();
    err_log.close();

    config.load_file("conTest");
    config.add_to_map("7", "cat");
    config.write_file("conTest");
    config.rename_file("conTest2");
    config.change_file_path("~/");
    std::string test = config.get_from_map("7");

    if (test.compare("cat") == 0) {
        return 1;
    } else {
        return 0;
    }
}

