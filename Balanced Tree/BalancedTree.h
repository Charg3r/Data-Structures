#pragma once
#include "Node.h"

class BalancedTree
{
public:
    BalancedTree();
    Node* getRoot();
    void setRoot(Node*);
    Node* insert(Node*, int, bool&);
    void preorder(Node*);
    void postorder(Node*);
    void inorder(Node*);
    void search(int);
    int counter(Node*);
    Node* previous(Node*);
    ~BalancedTree();

private:
    Node* root;
};

