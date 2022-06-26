#include "dataStructs.hpp"

int main(){
    DS::BST* tree = new DS::BST();
    tree->insert("jorge");
    tree->insert("allan");
    tree->insert("yasmin");
    tree->insert("joao");
    tree->insert("jorge");
    tree->insert("yasmin");
    tree->insert("lucas");
    tree->insert("lucas");
    DS::List* list = new DS::List();
    tree->convertToList(list);
    list->printList();
    delete tree;
    delete list;
    return 0;
}