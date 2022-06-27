#ifndef TREE_H
#define TREE_H

#include "wordCounter.hpp"
#include "list.hpp"
#include <string>
#include "memlog.h"

namespace Tree{
    class Node{
        friend class BST;

        wordCounter::wordCounter* value;
        Node* right;
        Node* left;

        public:
            Node(std::string word, Node* right, Node* left);
            Node(std::string word) : Node(word, nullptr, nullptr){}
            ~Node();
    };

    class BST{
        Node* root;
        long unsigned int nElements;
        long unsigned int counter;
        void convertToList(Node* n, List::StaticList* l);
        
        public:
            BST();
            void insert(std::string word);
            List::StaticList* convertToList();
            ~BST();
    };
}

#endif