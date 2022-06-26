#include "dataStructs.hpp"
#include <iostream>

DS::Cell::Cell(StringCounter str_c, DS::Cell* next){
    this->value = str_c;
    this->next = next;
}

DS::List::List(){
    this->first = nullptr;
    this->size = 0;
}

void DS::List::insert(StringCounter str_c){
    first = new DS::Cell(str_c, first);
    size++;
}

void DS::List::printList(){
    DS::Cell* current = first;
    while(current != nullptr){
        std::cout << current->value.word << " " << current->value.counter << "\n";
        current = current->next;
    }
}

DS::List::~List(){
    Cell* current = first;
    while(current != nullptr){
        Cell* aux = current;
        current = current->next;
        delete aux;
    }
}

DS::Node::Node(std::string str, Node* left, Node* right){
    this->value = new StringCounter(str);
    this->left = left;
    this->right = right;
}

DS::Node::~Node(){
    delete value;
    this->left = nullptr;
    this->right = nullptr;
}

DS::BST::BST(){
    this->root = nullptr;
    this->size = 0;
}

void DS::BST::insert(std::string str){
    if(root == nullptr){
        root = new Node(str);
        size++;
        return;
    }

    DS::Node* current = root;

    while(current != nullptr){
        if(current->value->word == str){
            current->value->counter++;
            return;
        } else if(current->value->word > str){
            if(current->left == nullptr){
                current->left = new DS::Node(str);
                size++;
                return;
            } else {
                current = current->left;
            }
        } else if(current->value->word < str){
            if(current->right == nullptr){
                current->right = new DS::Node(str);
                size++;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void DS::BST::convertSubtreeToList(DS::Node* current, DS::List* list){
    if(current == nullptr) return;

    BST::convertSubtreeToList(current->left, list);
    BST::convertSubtreeToList(current->right, list);

    list->insert(*(current->value));
    delete current;
}

void DS::BST::convertToList(DS::List* list){
    convertSubtreeToList(root, list);
}

DS::BST::~BST(){
    this->size = -1;
}