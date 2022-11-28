#pragma once
#include "Node.h"

class BST {
public:
    Node* root;

    BST();
    Node* constructTree(int input[], int size);
};

