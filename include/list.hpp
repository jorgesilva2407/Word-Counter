#ifndef LIST_H
#define LIST_H

#include "wordCounter.hpp"
#include "list.hpp"
#include "lexOrder.hpp"

namespace List{
    class StaticList(){        
        wordCounter::wordCounter* list;
        long unsigned int nElementos;
        void sort(LexOrder::LexOrder* LO, long unsigned int begin, long unsigned int end);
        
        public:
            List(Tree::BST* tree);
            void sort(LexOrder::LexOrder* LO) : sort(LO, 0, nElementos-1){}
            void print();
            ~List();
    }
}

#endif