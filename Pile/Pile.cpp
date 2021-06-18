#include "Pile.h"

void Pile::push(int d)
{
	Node* neu = new Node(d, nullptr);
	
	if (empty)
	{
		top = neu;
	}
	else
	{
		neu->setNext(top);
		top = neu;
	}
}

Node* Pile::pop()
{
	if (empty)
	{
		return nullptr;
	}
	else
	{
		Node* aux = top;
		top = top->getNext();
		return aux;
	}
}

Node* Pile::getTop()
{
	return top;
}

bool Pile::empty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
	return false;
	}
}
