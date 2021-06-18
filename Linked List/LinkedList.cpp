#include "LinkedList.h"

LinkedList::LinkedList()
{
	start = nullptr;
}


Node* LinkedList::getStart()
{
	return start;
}

void LinkedList::setStart(Node* s)
{
	start = s;
}

/*
Method that inserts at the head of the list.
input: n
output: n/a
*/

void LinkedList::insertStart(int n)
{
	Node* neu = new Node(n, nullptr);

	if (start == nullptr)
	{
		start = neu;
	}
	else
	{
		neu->setNext(start);
		start = neu;
	}
}

/*Inserta un nuevo nodo al final de la lista
input: f
output: n/a
Si no existe un nuevo nodo con anterioridad, se coloca este nodo en la posici�n start
(la posici�n inicial)
En caso de que exista, lo agrega al final
*/

void LinkedList::insertEnd(int f)
{
	Node* neu = new Node(f, nullptr);

	if (start == nullptr)
	{
		start = neu;
	}
	else
	{
		Node* bfr = start;
		Node* aux = start;

		while (aux != nullptr)
		{
			bfr = aux;
			aux = aux->getNext();
		}
		bfr->setNext(neu);
	}
}

/* M�todo que busca el Nodo
intput: s
output: n/a
Busca el nodo dado, si no lo encuentra, imprmir� un "not found"
*/

void LinkedList::searchNode(int s)
{
	Node* aux = start;

	while (aux != nullptr && s != aux->getData())
	{
		aux = aux->getNext();
	}
	if (aux == nullptr)
	{
		cout << "Item " << s << "not found" << endl;
	}
	else
	{
		cout << "Item " << s << "found" << endl;
	}
}

/*
Metodo que acomoda el dato introducido por orden ascendente
input: int
output: n/a
*/

void LinkedList::insertOrder(int d)
{
	Node* n = new Node(d, nullptr);

	if (start == nullptr)
	{
		start = n;
	}
	else
	{
		Node* aux1 = start;
		Node* aux2 = start;

		while (aux2 != nullptr && d > aux2->getData())
		{
			aux1 = aux2;
			aux2 = aux2->getNext();
		}

		if (aux1 == aux2) // Insrta el mas peque�o
		{
			n->setNext(start);
			start = n;
		}
		else if (aux2 == nullptr) // Insrta al final
		{
			aux1->setNext(n);
		}
		else // Insrta en el medio
		{
			n->setNext(aux2);
			aux1->setNext(n);
		}
	}
}

/*
M�todo que mezcla dos listas
input: LinkedList
output: n/a
Mezcla tanto la lista actual, como la que ingresa a la funcion, para
posteriormente eliminar los datos repetidos.
*/

void LinkedList::mixList(LinkedList list)
{
	Node* n = list.start;

	while (n->getNext() != nullptr)
	{
		this->insertOrder(n->getData());
		n = n->getNext();
	}

	//Se utiliza un auxiliar para observar el siguiente 
	//dato de la lista y evitar que se repitan.

	LinkedList newList;
	Node* m = this->start;
	Node* aux = this->start;
	aux = aux->getNext();

	while (m->getNext() != nullptr)
	{
		if (m->getData() != aux->getData())
		{
			newList.insertOrder(m->getData());
		}

		m = m->getNext();
		aux = aux->getNext();
	}

	*this = newList;
}

/*
Metodo que invierte el orden de los datos de la lista.
input: n/a
output: n/a
*/

void LinkedList::invertList()
{
	LinkedList* newList = new LinkedList();
	Node* n = start;

	if (n == nullptr)
	{
		cout << "Empty List" << endl;
	}

	while (n != nullptr)
	{
		newList->insertStart(n->getData());
		n = n->getNext();
	}

	*this = *newList;
}

/*Metodo que imprime la cantidad de nodos acumuladas en la lista
input: n/a
output: n/a
*/

int LinkedList::getLength()
{
	Node* n = start;
	int count = 0;

	while (n != nullptr)
	{
		n = n->getNext();
		count++;
	}

	return count;
}

/*Metodo que imprime el nodo ligado
input: n/a
output: n/a
*/

void LinkedList::print()
{
	Node* n = start;

	while (n != nullptr)
	{
		cout << n->getData() << endl;
		n = n->getNext();
	}
}

LinkedList::~LinkedList()
{
}

/*
Metodo que sobrecarga el operador << para imprimir una lista
Input: ostream& output, list LinkedList
Output: ostream& output
*/

ostream& operator<<(ostream& output, LinkedList& list)
{
	Node* n = list.start;

	output << "|| Contenido de la lista ligada ||" << endl << "==================================" << endl;

	do
	{
		if (n->getNext() != nullptr)
		{
			output << "       < " << n->getData() << ", " << n->getNext() << " >" << endl;
			n = n->getNext();
		}
		else
		{
			output << "       < " << n->getData() << ", " << "NULL" << " >" << endl;
			return output << endl;
		}
	} while (list.start != nullptr);
}

/*
Metodo que concatena dos listas.
input: LinkedList
output: n/a
A�ade todos los datos de la segunda lista al final de la primera.
*/

void LinkedList::operator+=(LinkedList list)
{
	Node* n = list.getStart();

	while (n != nullptr)
	{
		insertEnd(n->getData());
		n = n->getNext();
	}
}

void LinkedList::operator+=(int n)
{
	insertEnd(n);
}

// M�todo que sobrecarga el operador --, borra el �ltimo nodo de la lista.

void LinkedList::operator -- ()
{
	Node* aux = start;
	Node* pos = start;

	if (start == nullptr)
	{
		cout << "Error deleting, empty list" << endl;
	}

	while (aux->getNext() != nullptr)
	{
		pos = aux;
		aux = aux->getNext();
	}

	pos->setNext(nullptr);
}

// M�todo que sobrecarga el operador --, borra el primer nodo de la lista

void LinkedList::operator -- (int n)
{
	Node* pre = start;

	if (start == nullptr)
	{
		cout << "Empty List." << endl;
	}

	start = pre->getNext();
}