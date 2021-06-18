#include "Node.h"
#include <iostream>

Node::Node()
{
	data = 0;
	next = nullptr;
}

Node:: ~Node()
{
}

Node::Node(int dat, Node* nod)
{
	data = dat;
	next = nod;
}

int Node::getData()
{
	return data;
}

Node* Node::getNext()
{
	return next;
}

void Node::setData(int dat)
{
	data = dat;
}

void Node::setNext(Node* nod)
{
	next = nod;
}