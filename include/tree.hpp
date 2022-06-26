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
            ~Node();
    };

    class BST{
        Node* root;
        
        public:
            BST();
            insert(std::string word);
            ~BST();
    };
}

#endif