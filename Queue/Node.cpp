#include <iostream>
#include "Node.h"

Node::Node()
{
	key = 0;
	next = nullptr;
}



Node::Node(int k, string n, Node* nod)
{
	key = k;
	name = n;
	next = nod;
}

int Node::getKey()
{
	return key;
}

Node* Node::getNext()
{
	return next;
}

void Node::setKey(int k)
{
	key = k;
}

void Node::setNext(Node* nod)
{
	next = nod;
}

Node:: ~Node()
{
}