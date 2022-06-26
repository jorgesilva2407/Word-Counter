#ifndef DATA_STRUCTS
#define DATA_STRUCTS

#include "StringCounter.hpp"
#include <string>
#include <fstream>

namespace DS{
    class Cell{
        friend class List;

        StringCounter value;
        Cell* next;

        public:
            Cell(StringCounter str_c, Cell* next);
            Cell(StringCounter str_c) : Cell(str_c, nullptr){}
    };

    class List{
        friend class BST;
        Cell* first;
        int size;

        public:
            static std::ofstream out;
            static int medianOf;
            static int minimumPartition;

            List();
            void insert(StringCounter str_c);
            int getSize(){return size;}
            // void sort();
            // void selectionSort();
            void printList();
            ~List();

            List* operator+(List* l);
    };

    class Node{
        friend class BST;

        StringCounter* value;
        Node* left;
        Node* right;

        public:
            Node(std::string str, Node* left, Node* right);
            Node(std::string str) : Node(str, nullptr, nullptr){}
            ~Node();
    };

    class BST{
        Node* root;
        int size;
        void convertSubtreeToList(Node* current, List* list);

        public:
            BST();
            void insert(std::string str);
            int getSize(){return size;}
            void convertToList(List* list);
            ~BST();
    };
}

#endif