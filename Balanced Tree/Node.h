#pragma once
#include <iostream>
#include <ostream>

using namespace std;

class Node
{
public:
	Node();
	Node(int, int, Node*, Node*);
	int getData();
	int getFe();
	Node* getLeft();
	Node* getRight();
	void setData(int);
	void setFe(int);
	void setLeft(Node*);
	void setRight(Node*);
	~Node();

	//friend ostream& operator << (ostream&, Node*);

private:
	int data;
	int fe;
	Node* left;
	Node* right;
};

