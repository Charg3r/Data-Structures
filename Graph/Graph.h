// Graph.h
// Carlos G. Olivas Cordova / A01246040
// Andrick J. Perez Landa

#pragma once
#include <iostream>
#include <list>
#include <stack> 

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int); // Agrega arcos al grafo
	void DFS(int); // Recorrido del grafo en profundidad a partir de un nodo dado
	void BFS(int); // Recorrido del grado en anchura a partir de un nodo dado
	void printMatrix();
	void topologicalSort();
	bool Warshall(int, int);
	~Graph();

private:
	int vertices; // grado del grafo, numero de nodos
	list<int>* adjList; // lista de adyacentes para cada nodo
	bool** adjMatrix;
	void listDFS(int, bool[]); // rutina recursiva para realizar recorrido en profundidad
	void matrixDFS(int, bool[]);
	void recursiveSort(int, bool[], stack<int>&);
};