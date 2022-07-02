#include "lexOrder.hpp"

inline bool LexOrder::ignore(char c)
// Descrição: função que diz se um caractere deve ou não ser ignorado
// Entrada: um caractere
// Saida: se o caractere deve ser ignorado ou não
{
    switch(c){
        case ',':
            return true;
        case '.':
            return true;
        case '!':
            return true;
        case '?':
            return true;
        case ':':
            return true;
        case ';':
            return true;
        case '_':
            return true;
        default:
            return false;
    }
}

inline bool LexOrder::isUpperLetter(char c)
// Descrição: informa se um caractere é uma letra maiúscula
// Entrada: um caractere
// Saida: verdadeiro se for letra maiúscula e falso se não for
{
    return (c >= 'A' && c <= 'Z');
}

inline bool LexOrder::isLowerLetter(char c)
// Descrição: informa se um caractere é uma letra minúscula
// Entrada: um caractere
// Saida: verdadeiro se for letra minúscula e falso se não for
{
    return (c >= 'a' && c <= 'z');
}

inline char LexOrder::toLowerLetter(char c)
// Descrição: transforma uma letra minúscula em maiúcula
// Entrada: um caractere
// Saida: o carctere correspondente em minúscula
{
    if(!isUpperLetter(c)) throw "entrada não é uma letra maiúscula";
    else return (c - 'A' + 'a');
}

std::string LexOrder::toRegularString(std::string s)
// Descrição: transforma todos as letras maiúculas de uma string em minúsculas
// Entrada: uma string
// Saida: uma string com todas as letras em minúsculo
{
    std::string aux = "";

    for(long unsigned int i=0; i < s.size(); i++){
        if(ignore(s[i])) continue;
        if(isUpperLetter(s[i])) aux += toLowerLetter(s[i]);
        else aux += s[i];
    }

    return aux;
}

LexOrder::LexOrder::LexOrder()
// Descrição: inicializador da classe LexOrder
// Entrada: nenhuma
// Saida: nenhuma
{
    counter = (int) 'a';
}

void LexOrder::LexOrder::insert(char c)
// Descrição: define um valor o novo valor de c na ordem lexical
// Entrada: uma letra maiúscula
// Saida: nenhuma
{
    if(!isUpperLetter(c)) throw "caractere inválido na inserido na ordem lexical";
    else values[c - 'A'] = counter++;
}

inline int LexOrder::LexOrder::getValue(char c)
// Descrição: retorna o valor do caractere na ordem lexical
// Entrada: uma letra minúscula
// Saida: valor da letra na ordem lexical
{
    if(!isLowerLetter(c)) return (int)c;
    else return values[c - 'a'];
}

bool LexOrder::LexOrder::biggerThan(std::string s0, std::string s1)
// Descrição: retorna se a string s0 é maior que a string s1
// Entrada: duas strings
// Saida: retorna verdadeiro se a i-ésima letra de s0 for maior que a i-ésima letra de s1 ou se as k letras de s1 forem iguais as k primeiras letras de s0 e o tamanho de s0 for maior do que k
{
    for(long unsigned int i=0; i < s0.size() && i < s1.size(); i++){
        if(getValue(s0[i]) != getValue(s1[i])) return getValue(s0[i]) > getValue(s1[i]);
    }
    return s0.size() > s1.size();
}