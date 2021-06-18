#include "Queue.h"

Queue::Queue()
{
	front = nullptr;
	back = nullptr;
}

Node* Queue::getFront()
{
	return front;
}

Node* Queue::getBack()
{
	return back;
}

void Queue::setFront(Node* f)
{
	front = f;
}

void Queue::setBack(Node* b)
{
	back = b;
}

void Queue::insert(int nk, string nn)
{
    Node* aux = new Node(nk, nn, nullptr);

    if (front == nullptr) 
    {
        front = aux;
        back = aux;
    }
    else 
    {
        back->setNext(aux);
        back = aux;
    }
}

void Queue::del()
{
    if (front == nullptr) 
    {
        cout << "Fila Vacía" << endl;
    }
    else 
    {
        Node* aux = front;
        front = front->getNext();
        delete aux;

        if (front == nullptr) 
        {
            back = nullptr;
        }
    }
}

Queue::~Queue()
{
}
