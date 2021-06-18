#pragma once
#include "Node.h"

class BinaryTree
{
public:
    BinaryTree();

    Node* getRoot();
    void setRoot(Node*);

    void insert(int);
    void preorder(Node*);
    void postorder(Node*);
    void inorder(Node*);
    void search(int);
    int counter(Node*);

    Node* previous(Node*);
    Node* deletion(Node*, Node*);
    Node* deleteChild(Node*, Node*);
    Node* deleteChildren(Node*, Node*);

    ~BinaryTree();

private:
    Node* root;
};