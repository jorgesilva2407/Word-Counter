#include <iostream>
#include <string>
#include <fstream>
#include "memlog.h"
#include "lexOrder.hpp"
#include "tree.hpp"
#include "list.hpp"

int main(int argc, char** argv){
    try{
        // string auxiliar para receber entradas
        std::string buffer;

        // arquivo de entrada
        std::ifstream in;
        // arquivo de saida
        std::string out;
        
        // quantidade de elementos que deverão ser usados para escolher o pivô no quickSort
        int medianOf = 1;
        // menor partição que o quickSort deve criar
        int minPartition = 1;

        // indica se o log de memória está ativado
        bool activeMemLog = false;
        
        // captura os parâmetros passados como entrada
        for(int i=1; i < argc; i++){
            buffer = argv[i];
            if(buffer == "-i" || buffer == "-I"){
                i++;
                in.open(argv[i]);
            } else if(buffer == "-o" || buffer == "-O"){
                i++;
                out = argv[i];
            } else if(buffer == "-m" || buffer == "-M"){
                i++;
                medianOf = std::stoi(argv[i]);
                if(medianOf < 1) throw "valor inválido para mediana";
            } else if(buffer == "-S" || buffer == "-S"){
                i++;
                minPartition = std::stoi(argv[i]);
                if(minPartition < 1) throw "valor inválido para tamanho de menor partição";
            } else if(buffer == "-l" || buffer == "-L"){
                activeMemLog = true;
            }
        }

        // verifica se abertura dos arquivos ocorreu com sucesso
        if(!in.is_open()) throw "falha ao abrir o arquivo de entrada";

        // inicia log de memória
        char memLog[] = "memLog.out";
        iniciaMemLog(memLog);

        // define se o log de memória deve ou não ser escrito
        activeMemLog ? ativaMemLog():desativaMemLog();

        // captura a o termo #ORDEM do texto
        in >> buffer;

        // verifica se o arquivo de entrada está consistente com a organização especificada
        if(buffer != "#ORDEM") throw "Falha na organização do arquivo de entrada";

        // incializa ordem lexicográfica
        LexOrder::LexOrder* LO = new LexOrder::LexOrder();

        // insere novos valores da ordem lexicográfica
        for(int i=0; i < ALPHABETSIZE; i++){
            in >> buffer;

            LO->insert(buffer[0]);
        }
        
        // fase de captura do texto
        defineFaseMemLog(0);

        // captura o termo #TEXTO do texto
        in >> buffer;

        // verifica se o arquivo de entrada está consistente com a organização especificada
        if(buffer != "#TEXTO") throw "Falha na organização do arquivo de entrada";

        // inicializa a árvore binária que vai receber as palavras do texto
        Tree::BST* tree = new Tree::BST();

        // insere as palavras do texto na árvore
        while(in >> buffer){
            if(buffer[buffer.size() - 1] == '-'){
                std::string aux;
                if(in >> aux) buffer += aux;
            }

            tree->insert(LexOrder::toRegularString(buffer));
        }

        // fase de conversão de árvore em lista
        defineFaseMemLog(1);

        // acessa ou não o conteúdo da árvore para análise de localidade de referência
        if(activeMemLog) tree->accessTree();

        // converte a árvore em uma lista
        List::StaticList* list = tree->convertToList();
        delete tree;

        // define quais são os parâmetros dos métodos usados para otimizar o quickSort
        list->setMedian(medianOf);
        list->setPartition(minPartition);

        // fase de ordenação da lista
        defineFaseMemLog(2);

        // acessa ou não o conteúdo da lista para análise de localidade de referência
        if(activeMemLog) list->accessList();

        // ordena a lista de acordo com a ordem lexicográfica definida
        list->sort(LO);

        // desaloca a memória pertencente à ordem lexicográfica
        delete LO;

        // imprime a lista ordenada de acordo com a ordem lexicográfica
        list->print(out);
        delete list;

        // finaliza o log de memória
        finalizaMemLog();
    }

    catch (const char* e){
        std::cout << "ERRO: " << e << std::endl;
        exit(1);
    }

    return 0;
}