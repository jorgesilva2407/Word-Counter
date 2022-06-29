#ifndef LIST_H
#define LIST_H

#include "wordCounter.hpp"
#include "list.hpp"
#include "lexOrder.hpp"
#include <fstream>
#include <string>
#include "memlog.h"

namespace List{
    class StaticList{     
        wordCounter::wordCounter** list;
        long unsigned int nElements;
        
        long unsigned int counter;
        int medianOf;
        int minPartition;
        void sort(LexOrder::LexOrder* LO, long unsigned int begin, long unsigned int end);
        
        public:
            StaticList(long unsigned int size);
            void setMedian(int m);
            void setPartition(int p);
            void insert(wordCounter::wordCounter* value);
            void sort(LexOrder::LexOrder* LO);
            void print(std::string outFile);
            ~StaticList();
    };
}

#endif