#include "tree.hpp"

Tree::Node::Node(std::string word, Node* right, Node* left){
    this->value = new wordCounter::wordCoutner(word);
    this->right = right;
    this->left = left;
}

void Tree::Node::insert(std::string word){
    if(value->word == word){
        value->counter++;
        return;
    } else if(value->word > word){
        if(right == nullptr){
            right = new Node(word);
            return;
        } else {
            right->insert(word);
        }
    } else {
        if(left == nullptr){
            left = new Node(word);
            return;
        } else {
            left->insert(word);
        }
    }
}

Tree::Node::~Node(){
    this->value = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}

Tree::BST::BST(){
    this->nElementos = 0;
    this->root = nullptr;
}

void Tree::BST::insert(std::string word){
    root->insert(word);    
}