#ifndef STRING_COUNTER
#define STRING_COUNTER

#include <string>

struct StringCounter{
    std::string word;
    int counter;

    StringCounter(std::string str);
    StringCounter() : StringCounter("null"){}
};

#endif