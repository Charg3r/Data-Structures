#include "Node.h"

Node::Node()
{
	data = 0;
	fe = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int d, int f, Node* l, Node* r)
{
	data = d;
	fe = f;
	left = l;
	right = r;
}

int Node::getData()
{
	return data;
}

int Node::getFe()
{
	return fe;
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

void Node::setFe(int f)
{
	fe = f;
}

void Node::setLeft(Node* l)
{
	left = l;
}

void Node::setRight(Node* r)
{
	right = r;
}

Node::~Node()
{
}