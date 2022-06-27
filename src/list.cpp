#include "list.hpp"
#include "memlog.h"

List::StaticList::StaticList(unsigned long size){
    nElements = size;
    list = (wordCounter::wordCounter*)malloc(size*sizeof(wordCounter::wordCounter));
    medianOf = 0;
    minPartition = 0;
}

void List::StaticList::setMedian(int m){
    this->medianOf = m;
}

void List::StaticList::setPartition(int p){
    this->minPartition = p;
}

void List::StaticList::insert(wordCounter::wordCounter value, unsigned long position){
    list[position] = value;
    ESCREVEMEMLOG((long int)(&(list[position])),sizeof(wordCounter::wordCounter),1);
}

void List::StaticList::sort(LexOrder::LexOrder* LO, long unsigned int begin, long unsigned int end){
    return;
}

void List::StaticList::sort(LexOrder::LexOrder* LO){
    this->sort(LO, 0, nElements);
}

void List::StaticList::print(std::string outFile){
    std::ofstream out;
    out.open(outFile);
    if(!out.is_open()) throw "falha ao abrir o arquivo";

    for(long unsigned int i=0; i < nElements; i++){
        out << list[i].word << " " << list[i].counter << std::endl;
        LEMEMLOG((long int)(&(list[i])),sizeof(wordCounter::wordCounter),1);
    }
    
    out.close();
}

List::StaticList::~StaticList(){
    nElements = 0;
    free(list);
}