#pragma once
#include <string>

using namespace std;

class Node
{
public:
	Node();
	Node(int, string, Node*);
	int getKey();
	Node* getNext();
	void setKey(int);
	void setNext(Node*);
	~Node();

private:
	int key;
	string name;
	Node* next;
};