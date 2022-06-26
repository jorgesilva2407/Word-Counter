#ifndef WORD_COUNTER
#define WORD_COUNTER

#include <string>

// struct com o objetivo de armazenar os valores das palaravas e a quatidade de vazes a palavra foi contada

namespace wordCounter{
    struct wordCoutner{
        std::string word;
        int counter;

        stringCoutner(std::string s){
            word = s;
            counter = 1;
        }
    };
}

#endif