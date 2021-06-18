// Node.h
// Carlos Olivas / A01246040

#include "Node.h"

Node::Node()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int d, Node* nl, Node* nr)
{
	data = d;
	left = nl;
	right= nr;
}

int Node::getData()
{
	return data;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

void Node::setData(int d)
{
	data = d;
}


void Node::setLeft(Node* nl)
{
	left = nl;
}

void Node::setRight(Node* nr)
{
	right = nr;
}

Node::~Node()
{
}