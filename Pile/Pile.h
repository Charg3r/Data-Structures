#pragma once
#include "Node.h"

class Pile
{
public:
	void push(int);
	Node* pop();
	Node* getTop();
	bool empty();

private:
	Node* top;

};

