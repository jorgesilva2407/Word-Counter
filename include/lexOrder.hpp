#ifndef LEX_ORDER
#define LEX_ORDER

#include <string>

// constante que representa o número de letras do alfabeto
#define ALPHABETSIZE 26

namespace LexOrder{
    inline bool ignore(char c);
    inline bool isUpperLetter(char c);
    inline bool isLowerLetter(char c);
    inline char toLowerLetter(char c);
    std::string toRegularString(std::string c);

    class LexOrder{
        int values[26];
        int counter;
        inline int getValue(char c);

        public:
            LexOrder();
            void insert(char c);
            bool biggerThan(std::string s0, std::string s1);
    };
}

#endif