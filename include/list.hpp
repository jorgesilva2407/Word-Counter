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
        int nElements;
        
        int counter;
        int medianOf;
        int minPartition;
        
        void selectionSort(wordCounter::wordCounter** list, LexOrder::LexOrder* LO, int begin, int end);
        void quickSort(wordCounter::wordCounter** list, LexOrder::LexOrder* LO, int begin, int end);
        void partition(int begin, int end,int *i, int *j, wordCounter::wordCounter** list, LexOrder::LexOrder* LO);
        void order(int begin, int end, wordCounter::wordCounter** list, LexOrder::LexOrder* LO);
        
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