// Node.cpp
// Carlos Olivas / A01246040

#pragma once

class Node
{
public:
	Node();
	Node(int, Node*, Node*);
	int getData();
	Node* getLeft();
	Node* getRight();
	void setData(int);
	void setLeft(Node*);
	void setRight(Node*);
	~Node();

private:
	int data;
	Node *left, *right;
};