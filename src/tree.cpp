#include "tree.hpp"

Tree::Node::Node(std::string word, Node* right, Node* left)
// Descrição: método construtor da classe Node
// Entrada: recebe uma string, e ponteiros para dois outros nodes
// Saída: nenhuma
{
    this->value = new wordCounter::wordCoutner(word);
    this->right = right;
    this->left = left;
}

Tree::Node::~Node()
// Descrição: método destrutor da classe node
// Entrada: nenhuma
// Saída: nenhuma
{
    this->value = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}

Tree::BST::BST()
// Descrição: método construtor da classe BST
// Entrada: nenhuma
// Saída: nenhuma
{
    this->nElements = 0;
    this->root = nullptr;
}

void Tree::BST::insert(std::string word)
// Descrição: insere um elemento na árvore
// Entrada: uma string
// Saída: nenhuma
{
    Node* current = root;
    while(current != nullptr){
        if(current->value->word == word){
            current->value->counter++;
        } else if(current->value->word > word){
            if(current->left == nullptr){
                current->left = new Node(word);
                nElements++;
                return;
            } else {
                current = current->left;
            }
        } else {
            if(current->right == nullptr){
                current->right = new Node(word);
                nElements++;
                return;
            } else {
                current = current->right;
            }
        }
    }
}