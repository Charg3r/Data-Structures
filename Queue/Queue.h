#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue();
    Node* getFront();
    Node* getBack();
    void setFront(Node*);
    void setBack(Node*);
    void insert(int, string);
    void del();
    ~Queue();

};