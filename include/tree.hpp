#ifndef TREE_H
#define TREE_H

#include "wordCounter.hpp"
#include <string>

namespace Tree{
    class Node{
        friend class BST;

        wordCounter::wordCoutner* value;
        Node* right;
        Node* left;

        public:
            Node(std::string word, Node* right, Node* left);
            Node(std::string word) : Node(word, nullptr, nullptr){}
            ~Node();
    };

    class BST{
        Node* root;
        long unsigned int nElementos;
        
        public:
            BST();
            void insert(std::string word);
    };
}

#endif