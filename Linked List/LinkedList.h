#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	Node* getStart();
	void setStart(Node*);
	void insertStart(int);
	void insertEnd(int);
	void searchNode(int);
	void insertOrder(int);
	void mixList(LinkedList);
	void invertList();
	int getLength();
	void print();
	virtual ~LinkedList();

	friend ostream& operator << (ostream&, LinkedList&);
	void operator += (LinkedList n);
	void operator += (int n);
	void operator -- ();
	void operator -- (int);

private:
	Node* start;
};