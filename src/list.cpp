#include "list.hpp"
#include "memlog.h"

List::StaticList::StaticList(unsigned long size)
// Descrição: Método construtor da classe StaticList
// Entrada: tamanho da lista que deverá ser criada
// Saída: nenhuma
{
    nElements = size;
    list = (wordCounter::wordCounter*)malloc(size*sizeof(wordCounter::wordCounter));
    medianOf = 0;
    minPartition = 0;
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

void List::StaticList::insert(wordCounter::wordCounter value, unsigned long position)
// Descrição: insere um valor na lista
// Entrada: um valor e a posiçõa na qual ele será inserido
// Saída: nenhuma
{
    list[position] = value;
    ESCREVEMEMLOG((long int)(&(list[position])),sizeof(wordCounter::wordCounter),1);
}

void List::StaticList::sort(LexOrder::LexOrder* LO, long unsigned int begin, long unsigned int end)
// Descrição: método auxiliar para ordenar uma lista de acordo com uma redefinição da ordem lexicográfica
// Entrada: uma ordem lexicográfica, o começo e o fim dos intervalos a serem ordenaods
// Saída: nenhuma
{
    return;
}

void List::StaticList::sort(LexOrder::LexOrder* LO)
// Descrição: ordena uma lista de acordo com a ordem lexicográfica informada
// Entrada: uma ordem lexicográfica
// Saída: nenhuma
{
    this->sort(LO, 0, nElements);
}

void List::StaticList::print(std::string outFile)
// Descrição: imprime os elementos da lista
// Entrada: o nome do arquivo de saida
// Saída: nenhuma
{
    std::ofstream out;
    out.open(outFile);
    if(!out.is_open()) throw "falha ao abrir o arquivo";

    for(long unsigned int i=0; i < nElements; i++){
        out << list[i].word << " " << list[i].counter << std::endl;
        LEMEMLOG((long int)(&(list[i])),sizeof(wordCounter::wordCounter),1);
    }
    
    out.close();
}

List::StaticList::~StaticList()
// Descrição: método destrutor da classe StaticList
// Entrada: nenhuma
// Saída: nenhuma
{
    nElements = 0;
    free(list);
}