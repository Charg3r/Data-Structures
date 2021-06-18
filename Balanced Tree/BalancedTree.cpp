#include "BalancedTree.h"

using namespace std;

BalancedTree::BalancedTree()
{
    root = nullptr;
}

Node* BalancedTree::getRoot()
{
	return root;
}

void BalancedTree::setRoot(Node* r)
{
    root = r;
}

Node* BalancedTree::insert(Node* n, int d, bool &b)
{
    Node* node1, *node2;

    if (n != nullptr) 
    {
        if (d < n->getData())
        {

            n->setLeft(insert(n->getLeft(), d, b));

            if (b == true) 
            {
                switch (n->getFe()) 
                {

                case 1: n->setFe(0); b = false;
                    break;

                case 0: n->setFe(-1);
                    break;

                case -1:
                    node1 = n->getLeft();
                    if (node1->getFe() < 0) 
                    {
                        n->setLeft(node1->getRight());
                        node1->setRight(n);
                        n->setFe(0);
                        n = node1;
                    }
                    else
                    {
                        node2 = node1->getRight();
                        n->setLeft(node2->getRight());
                        node2->setRight(n);
                        node1->setRight(node2->getLeft());
                        node2->setLeft(node1);

                        if (node2->getFe() == -1) 
                        {
                            n->setFe(1);
                        }
                        else 
                        {
                            n->setFe(0);
                        }
                        if (node2->getFe() == 1) 
                        {
                            node1->setFe(0);
                        }
                        else 
                        {
                            node1->setFe(0);
                        }
                        n = node2;
                    }
                    n->setFe(0);
                    b = false;
                    break;
                }
            }
        }
        else if (d > n->getData()) 
        {
            n->setRight(insert(n->getRight(), d, b));

            if (b == true) 
            {
                switch (n->getFe()) 
                {
                case -1: n->setFe(0); b = false;
                    break;

                case 0: n->setFe(1);
                    break;

                case 1:
                    node1 = n->getRight();

                    if (node1->getFe() > 0) 
                    {
                        n->setRight(node1->getLeft());
                        node1->setLeft(n);
                        n->setFe(0);
                        n = node1;
                    }
                    else
                    {
                        node2 = node1->getLeft();
                        n->setRight(node2->getLeft());
                        node2->setLeft(n);
                        node1->setLeft(node2->getRight());
                        node2->setRight(node1);

                        if (node2->getFe() == 1) 
                        {
                            n->setFe(-1);
                        }
                        else 
                        {
                            n->setFe(0);
                        }
                        if (node2->getFe() == -1) 
                        {
                            node1->setFe(1);
                        }
                        else 
                        {
                            node1->setFe(0);
                        }
                        n = node2;
                    }
                    n->setFe(0);
                    b = false;
                    break;
                }
            }
        }
        else 
        {
            cout << "Repeated data." << endl;
        }
    }
    else 
{
        n = new Node(d, 0, nullptr, nullptr);
        b = true;
    }

    return n;
}

void BalancedTree::preorder(Node* aux)
{
	if (aux != nullptr) 
	{
		cout << aux;
		preorder(aux->getLeft());
		preorder(aux->getRight());
	}
}

void BalancedTree::postorder(Node* aux)
{
	if (aux != nullptr) 
	{
		postorder(aux->getLeft());
		postorder(aux->getRight());
		cout << aux;
	}
}

void BalancedTree::inorder(Node* aux)
{
	if (aux != nullptr) {
		inorder(aux->getLeft());
		cout << aux;
		inorder(aux->getRight());
	}
}

void BalancedTree::search(int)
{
}

int BalancedTree::counter(Node* aux)
{
    int cont = 1;

    if (aux != nullptr) {
        cont += counter(aux->getLeft());
        cont += counter(aux->getRight());
        return cont;

    }
    else 
    {
        return 0;
    }
}

Node* BalancedTree::previous(Node* n)
{
    Node* before = root;
    Node* right = root;
    Node* left = root, * aux = root;

    if (n == root) 
    {
        cout << "No se puede acceder al nodo anterior a una raiz." << std::endl;
        return n;
    }

    while (before != nullptr && before->getData() != n->getData()) {

        aux = before;

        right = before->getRight();
        left = before->getLeft();

        if (right != nullptr) 
        {
            if (n->getData() < before->getData()) 
            {
                before = before->getLeft();
            }
            else 
            {
                before = before->getRight();
            }
        }
        else if (left != nullptr)
        {
            if (n->getData() < before->getData()) 
            {
                before = before->getLeft();
            }
            else 
            {
                before = before->getRight();
            }
        }
        else 
        {
            break;
        }
    }

    return aux;
}

BalancedTree::~BalancedTree()
{
}