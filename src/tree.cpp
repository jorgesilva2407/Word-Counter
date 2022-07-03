#include "tree.hpp"
#include "memlog.h"

Tree::Node::Node(std::string word, Node* right, Node* left)
// Descrição: método construtor da classe Node
// Entrada: recebe uma string, e ponteiros para dois outros nodes
// Saída: nenhuma
{
    this->value = new wordCounter::wordCounter(word);
    this->right = right;
    this->left = left;
}

Tree::Node::~Node()
// Descrição: método destrutor da classe node
// Entrada: nenhuma
// Saída: nenhuma
{
    this->value = nullptr;
    delete right;
    delete left;
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
    if(word == "") return;

    if(root == nullptr){
        root = new Node(word);
        nElements++;
        ESCREVEMEMLOG((long int)(root), sizeof(Node), 0);
        return;
    }
    
    Node* current = root;
    while(current != nullptr){
        LEMEMLOG((long int)(current), sizeof(Node), 0);
        if(current->value->word == word){
            current->value->counter++;
            return;
        } else if(current->value->word > word){
            if(current->left == nullptr){
                current->left = new Node(word);
                nElements++;
                ESCREVEMEMLOG((long int)(current->left), sizeof(Node), 0);
                return;
            } else {
                current = current->left;
            }
        } else {
            if(current->right == nullptr){
                current->right = new Node(word);
                nElements++;
                ESCREVEMEMLOG((long int)(current->right), sizeof(Node), 0);
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void Tree::BST::convertToList(Tree::Node* n, List::StaticList* l)
// Descrição: método auxiliar que usado para converter uma árvore em uma lista
// Entrada: recebe um nó da árvore e uma lista
// Saida: nenhuma
{
    if(n == nullptr) return;
    
    LEMEMLOG((long int)(n), sizeof(Node), 0);
    convertToList(n->left, l);

    l->insert(n->value);
    
    LEMEMLOG((long int)(n), sizeof(Node), 0);
    convertToList(n->right, l);
    return;
}

void Tree::BST::accessTree(Tree::Node* n)
// Descrição: acessa um nó específico e seus filhos
// Entrada: o nó a ser acessado
// Saída: nenhuma
{
    if(n == nullptr) return;
    
    LEMEMLOG((long int)(n), sizeof(Node), 0);
    accessTree(n->left);
    LEMEMLOG((long int)(n), sizeof(Node), 0);
    accessTree(n->right);
    LEMEMLOG((long int)(n), sizeof(Node), 0);
}

List::StaticList* Tree::BST::convertToList()
// Descrição: método que transforma uma árvore em uma lista
// Entrada: nenhuma
// Saida: retorna uma lista com todos os elementos da árvore, ordenados de forma descrescente de acordo com o operador < padrão de strings
{
    List::StaticList* aux = new List::StaticList(nElements);
    this->convertToList(root, aux);
    return aux;
}

void Tree::BST::accessTree()
// Descrição: acessa todos os elementos da árvore
// Entrada: nenhuma
// Saída: nenhuma
{
    this->accessTree(root);
}

Tree::BST::~BST()
// Descrição: método destrutor da classe BST
// Entrada: nenhuma
// Saida: nenhuma
{
    nElements = 0;
    delete root;
}