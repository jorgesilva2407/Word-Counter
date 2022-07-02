#include "list.hpp"
#include "memlog.h"

List::StaticList::StaticList(unsigned long size)
// Descrição: Método construtor da classe StaticList
// Entrada: tamanho da lista que deverá ser criada
// Saída: nenhuma
{
    nElements = size;
    list = (wordCounter::wordCounter**)malloc(size*sizeof(wordCounter::wordCounter*));
    medianOf = 0;
    minPartition = 0;
    counter = 0;
}

void List::StaticList::setMedian(int m)
// Descrição: define quantos elementos será escolhidos para se escolher o pivô no momento de realiza o quickSort
// Entrada: um número inteiro
// Saída: nenhuma
{
    this->medianOf = m;
}

void List::StaticList::setPartition(int p)
// Descrição: define o menor tamanho possível que uma partição pode ter durante o quickSort
// Entrada: um número inteiro
// Saída: nenhuma
{
    this->minPartition = p;
}

void List::StaticList::insert(wordCounter::wordCounter* value)
// Descrição: insere um valor na lista
// Entrada: um valor e a posiçõa na qual ele será inserido
// Saída: nenhuma
{
    list[counter] = value;
    ESCREVEMEMLOG((long int)(&(list[counter])),sizeof(wordCounter::wordCounter),1);
    counter++;
}

void List::StaticList::selectionSort(wordCounter::wordCounter** list, LexOrder::LexOrder* LO, int begin, int end){
    for(int i = begin; i < end; i++){
        int min = i;
        for(int j = i+1; j <= end; j++){
            if(LO->biggerThan(list[min]->word, list[j]->word)){
                min = j;
            }
        }
        wordCounter::wordCounter* aux = list[i];
        list[i] = list[min];
        list[min] = aux;
    }
}

void List::StaticList::partition(int begin, int end,int *i, int *j, wordCounter::wordCounter** l, LexOrder::LexOrder* LO){
    *i = begin; *j = end;

    wordCounter::wordCounter** pivotCandidates = (wordCounter::wordCounter**)malloc(medianOf*sizeof(wordCounter::wordCounter*));
    int step = (end - begin + 1)/(medianOf - 1);
    int cursor = begin;
    for(int i=0; i < medianOf; i++){
        pivotCandidates[i] = l[cursor];
        cursor += step;
    }
    selectionSort(pivotCandidates, LO, 0, medianOf-1);
    wordCounter::wordCounter* pivot = pivotCandidates[(medianOf/2)];

    do
    {
        while (LO->biggerThan(pivot->word, l[*i]->word)) (*i)++;
        while (LO->biggerThan(l[*j]->word, pivot->word) && l[*j]->word != pivot->word) (*j)--;
        if (*i <= *j){
            wordCounter::wordCounter* aux = l[*i];
            l[*i] = l[*j];
            l[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void List::StaticList::order(int begin, int end, wordCounter::wordCounter** l, LexOrder::LexOrder* LO){
    if(end - begin + 1 <= minPartition || end - begin + 1 <= medianOf){
        selectionSort(list, LO, begin, end);
    }
    int i, j;
    partition(begin, end, &i, &j, l, LO);
    if (begin < j) order(begin, j, l, LO);
    if (i < end) order(i, end, l, LO);
}

void List::StaticList::sort(LexOrder::LexOrder* LO)
// Descrição: ordena uma lista de acordo com a ordem lexicográfica informada
// Entrada: uma ordem lexicográfica
// Saída: nenhuma
{
    this->order(0, nElements-1, list, LO);
}

void List::StaticList::print(std::string outFile)
// Descrição: imprime os elementos da lista
// Entrada: o nome do arquivo de saida
// Saída: nenhuma
{
    std::ofstream out;
    out.open(outFile);
    if(!out.is_open()) throw "falha ao abrir o arquivo";

    for(int i=0; i < nElements; i++){
        out << list[i]->word << " " << list[i]->counter << std::endl;
        LEMEMLOG((long int)(&(list[i])),sizeof(wordCounter::wordCounter),1);
    }
    
    out.close();
}

List::StaticList::~StaticList()
// Descrição: método destrutor da classe StaticList
// Entrada: nenhuma
// Saída: nenhuma
{
    for(int i=0; i < nElements; i++){
        delete list[i];
    }
    free(list);
    nElements = 0;
}