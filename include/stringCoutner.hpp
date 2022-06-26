#ifndef STRING_COUNTER
#define STRING_COUNTER

#include <string>

// struct com o objetivo de armazenar os valores das palaravas e a quatidade de vazes a palavra foi contada

namespace stringCounter{
    struct stringCoutner{
        std::string word;
        int counter;

        stringCoutner(std::string s){
            word = s;
            counter = 1;
        }
    };
}

#endif