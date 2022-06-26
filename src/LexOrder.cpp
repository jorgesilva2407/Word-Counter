#include "LexOrder.hpp"

#define TO_LOWER 32

LexOrder::LexOrder::LexOrder(){
    counter = 0;
    for(int i=0; i < NUMBER_OF_LETTERS; i++){
        order[i] = i;
    }
}

LexOrder::LexOrder::~LexOrder(){
    for(int i=0; i < NUMBER_OF_LETTERS; i++){
        order[i] = -1;
    }
}

inline bool LexOrder::isLetter(char c){
    return (c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z');
}

inline bool LexOrder::isUpper(char c){
    return c >= 'A' && c <= 'Z';
}

inline char LexOrder::toLower(char c){
    return char(c+TO_LOWER);
}

void LexOrder::LexOrder::insert(char c){
    if(!isLetter(c)) return;
    c = isUpper(c) ? toLower(c) : c;
    order[c - 'a'] = counter;
    counter++;
}

inline int LexOrder::LexOrder::getValue(char c){
    return order[c - 'a'];
}

bool LexOrder::LexOrder::biggerThan(std::string a, std::string b){
    for(int i=0 ; i < a.size() && i <  b.size(); i++){
        if(!isLetter(a[i]) && !isLetter(b[i])){
            return a[i] > b[i];
        }

        if(!isLetter(a[i])) return a[i] > 'z';
        if(!isLetter(b[i])) return b[i] < 'a';

        if(getValue(a[i]) != getValue(b[i])) return getValue(a[i]) > getValue(b[i]);
    }

    if(a.size() <= b.size()) return false;
    else return true;
}