#ifndef LEX_ORDER
#define LEX_ORDER

#include <fstream>
#include <string>
#define NUMBER_OF_LETTERS 26

namespace LexOrder{

    inline bool isLetter(char c);
    inline bool isUpper(char c);
    inline char toLower(char c);

    class LexOrder{
        private:
            int order[NUMBER_OF_LETTERS];
            int counter;

            inline int getValue(char c);

        public:
            LexOrder();

            void insert(char c);
            bool biggerThan(std::string a, std::string b);

            ~LexOrder();
    };
}

#endif