#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
}

Node* BinaryTree::getRoot()
{
	return root;
}

void BinaryTree::setRoot(Node* r)
{
	root = r;
}

void BinaryTree::insert(int d)
{
    Node* n = new Node(d, nullptr, nullptr);

    if (root == nullptr) 
    {
        root = n;
    }
    else 
    {
        Node* aux1 = root;
        Node* aux2 = root;

        while (aux2 != nullptr && aux2->getData() != n->getData()) 
        {
            aux1 = aux2;
            if (aux1->getData() <= n->getData()) 
            {
                aux2 = aux2->getRight();
            }
            else 
            {
                aux2 = aux2->getLeft();
            }
        }

        if (aux2 != nullptr) 
        {
            cout << "Dato repetido." << endl;
            delete n;
        }
        else 
        {
            if (aux1->getData() > n->getData()) 
            {
                aux1->setLeft(n);
            }
            else 
            {
                aux1->setRight(n);
            }
        }
    }
}

void BinaryTree::preorder(Node* n)
{
    if (n != nullptr) 
    {
        cout << n->getData();
        preorder(n->getLeft());
        preorder(n->getRight());
    }
}

void BinaryTree::postorder(Node* n)
{
    if (n != nullptr) 
    {
        postorder(n->getLeft());
        postorder(n->getRight());
        cout << n->getData();
    }
}

void BinaryTree::inorder(Node* n)
{
    if (n != nullptr)
    {
        inorder(n->getLeft());
        cout << n->getData();
        inorder(n->getRight());
    }
}

void BinaryTree::search(int d)
{
    Node* bfr = root;
    Node* aux = root;

    while (aux != nullptr && aux->getData() != d)
    {
        bfr = aux;

        if (d < aux->getData())
        {
            aux = aux->getLeft();
        }
        else {
            aux = aux->getRight();
        }
    }

    if (aux == nullptr)
    {
        cout << "Node not found in tree" << endl;
    }
    else
    {
        cout << "Node found in tree" << endl;
    }
}

int BinaryTree::counter(Node* aux)
{
    int count = 0;

    if (aux != nullptr)
    {
        count = count + counter(aux->getLeft());
        count = count + counter(aux->getRight());
        count++;
    }

    return count;
}

Node* BinaryTree::previous(Node* n) {
    
    /*
    Funcion que recibira un nodo y devolvera aquel que este antes de el.
    Entrada: Node
    Salida: Node
    */

    Node* before = root;
    Node* right = root;
    Node* left = root, * aux = root;

    if (n == root) 
    {
        std::cout << "previous[FALSE]: No se puede acceder al nodo anterior a la raiz" << std::endl;
        return n;
    }

    while (before != nullptr && before->getData() != n->getData()) 
    {
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

Node* BinaryTree::deletion(Node* bfr, Node* aux)
{
    if (aux == root)
        return nullptr;
    else 
    {
        if (bfr->getRight() == aux)
            bfr->setRight(nullptr);
        else
            bfr->setLeft(nullptr);
        return bfr;
    }
}

Node* BinaryTree::deleteChild(Node* bfr, Node* aux)
{
    if (aux == root)
    {
        if (root->getLeft() == nullptr)
            root = root->getRight();
        else
            root = root->getLeft();
        delete aux;
        return root;
    }
    else 
    {
        Node* child; // el que borro tiene hijo der o izq
        if (aux->getRight() == NULL)
            child = aux->getLeft();
        else
            child = aux->getRight();
        if (bfr->getRight() == aux) // el que borro es hijo izq o der
            bfr->setRight(child);
        else
            bfr->setLeft(child);
        delete aux;
        return bfr;
    }
}

Node* BinaryTree::deleteChildren(Node* bfr, Node* aux)
{
    Node* bfrd = aux->getRight(), * auxd = bfrd;

    while (auxd->getLeft() != nullptr) // busco sustituto del nodo que borro, el mas izquierdo de la derecha
    {
        bfrd = auxd;
        auxd = auxd->getLeft();
    }
    if (aux == root) // el nodo que borro es raiz con dos hijos
    {
        if (auxd != bfrd)
        {
            bfrd->setLeft(auxd->getRight());
            auxd->setRight(bfrd);
        }
        auxd->setLeft(aux->getLeft());
        delete aux;
        return auxd;
    }
    else // el nodo que borro es cualquiera
    {
        if (auxd == bfrd) // el sustituto es inmediato derecho del que borro
            auxd->setLeft(aux->getLeft());
        else
        {
            bfrd->setLeft(auxd->getRight());
            auxd->setLeft(aux->getLeft());
            auxd->setRight(aux->getRight());
        }
        if (bfr->getRight() == aux) // el nodo que borro es hijo derecho
            bfr->setRight(auxd);
        else
            bfr->setLeft(auxd); // el que borro es hijo izquierdo
        delete aux;
        return bfr;
    }
}

BinaryTree::~BinaryTree()
{
}