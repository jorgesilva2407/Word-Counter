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

void List::StaticList::accessList()
// Descrição: acessa todos os elementos da lista com finalidade de computar a distância de pilha
// Entrada: nenhuma
// Saída: nenhuma
{
    for(int i=0; i < nElements; i++){
        LEMEMLOG((long int)(&(list[i])),sizeof(wordCounter::wordCounter*),1);
    }
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

void List::StaticList::selectionSort(wordCounter::wordCounter** list, LexOrder::LexOrder* LO, int begin, int end)
// Definição: ordena uma partição de uma lista utilizando o método de seleção
// Entrada: recebe uma lista, uma ordem lexicográfica, o índice do início da partição e o índice do fim da partição
// Saida: nenhuma
{
    for(int i = begin; i < end; i++){
        int min = i;
        for(int j = i+1; j <= end; j++){
            if(LO->biggerThan(list[min]->word, list[j]->word)){
                min = j;
            }
            LEMEMLOG((long int)(&(list[min]->word)),sizeof(wordCounter::wordCounter),1);
            LEMEMLOG((long int)(&(list[j]->word)),sizeof(wordCounter::wordCounter),1);
        }
        wordCounter::wordCounter* aux = list[i];
        list[i] = list[min];
        list[min] = aux;
        ESCREVEMEMLOG((long int)(&(list[i])),sizeof(wordCounter::wordCounter*),1);
        ESCREVEMEMLOG((long int)(&(list[min])),sizeof(wordCounter::wordCounter*),1);
    }
}

void List::StaticList::partition(int begin, int end,int *i, int *j, wordCounter::wordCounter** l, LexOrder::LexOrder* LO)
// Descrição: particiona uma partição de um vetor estático
// Entrada: os índices de início e fim da partição atual, referência para o início e fim das novas partições, um vetor estático e uma ordme lexicográfica
// Saída: os índices de início e fim das novas partições
{
    *i = begin; 
    *j = end;
    std::string pivot = "";

    if(medianOf > 1 && (end - begin + 1) > medianOf){
        wordCounter::wordCounter** pc = (wordCounter::wordCounter**)malloc(medianOf*sizeof(wordCounter::wordCounter*));
        for(int i=0; i < medianOf; i++){
            pc[i] = l[begin + i];
        }
        pivot = pc[medianOf/2]->word;
        free(pc);
    } else {
        pivot = l[begin]->word;
    }

    do
    {
        while (LO->biggerThan(pivot, l[*i]->word)){
            (*i)++;
            LEMEMLOG((long int)(&(l[*i]->word)),sizeof(wordCounter::wordCounter),1);
        }
        while ((LO->biggerThan(l[*j]->word, pivot)) && (l[*j]->word != pivot)){
            (*j)--;
            LEMEMLOG((long int)(&(l[*j]->word)),sizeof(wordCounter::wordCounter),1);
        }
        if (*i <= *j){
            wordCounter::wordCounter* aux = l[*i];
            l[*i] = l[*j];
            l[*j] = aux;
            (*i)++; (*j)--;
            ESCREVEMEMLOG((long int)(&(l[*i])),sizeof(wordCounter::wordCounter*),1);
            ESCREVEMEMLOG((long int)(&(l[*j])),sizeof(wordCounter::wordCounter*),1);
        }
    } while (*i <= *j);
}

void List::StaticList::order(int begin, int end, wordCounter::wordCounter** l, LexOrder::LexOrder* LO)
// Descrição: vai particionando as partições até que elas atinjam o tamanho mínimo
// Entrada: o índices de início e fim da partição atual, um vetor estático e uma ordem lexicográfica
// Saída: nenhuma
{
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
    
    out << "#FIM" << std::endl;
    
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