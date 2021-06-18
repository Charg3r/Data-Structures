// Graph.cpp
// Carlos G. Olivas Cordova / A01246040
// Andrick J. Perez Landa

#include "Graph.h"

Graph::Graph(int v)
{
	vertices = v;
	adjList = new list<int>[vertices];

	adjMatrix = new bool* [vertices];

	for (int i = 0; i < vertices; i++) 
	{
		adjMatrix[i] = new bool[vertices];

		for (int j = 0; j < vertices; j++)
			adjMatrix[i][j] = false;
	}
}

void Graph::addEdge(int source, int destination)
{
	/*
	Metodo que crea arcos entre nodos
	ENTRADA: source (nodo inicial), destination (nodo destino)
	SALIDA: n/a
	COMPLEJIDAD: O(N)
	*/
	adjMatrix[source][destination] = true;
	adjMatrix[destination][source] = false;

	adjList[source].push_back(destination);
	adjList[source].sort();
	list<int>::iterator i;

	cout << source << " >> ";

	for (i = adjList[source].begin(); i != adjList[source].end(); ++i)
		cout << *i << " ";
	cout << endl;
}


void Graph::DFS(int node)
{
	/*
	Metodo que hace un recorrido en profundidad tomando un nodo como entrada.
	ENTRADA: node
	SALIDA: n/a
	COMPLEJIDAD: O(N)
	*/

	bool* visitedL = new bool[vertices]; // se marcan todos los nodos como no visitados para iniciar el recorrido
	bool* visitedM = new bool[vertices];

	for (int i = 0; i < vertices; i++)
		visitedL[i] = false;

	for (int i = 0; i < vertices; i++)
		visitedM[i] = false;
	
	cout << " Lista ";
	cout << " - ";
	listDFS(node, visitedL);  // Llama a la rutina recursiva que realiza el recorrido

	cout << "\n Matriz ";
	cout << " - ";
	matrixDFS(node, visitedM);
}

void Graph::BFS(int node)
{
	/*
	Metodo que hace un recorrido de anchura tomando un nodo como entrada.
	ENTRADA: node
	SALIDA: n/a
	COMPLEJIDAD: O(N^2)
	*/

	bool* visited = new bool[vertices];
	
	for (int i = 0; i < vertices; i++)
		visited[i] = false;
	
	list<int> queue; // lista de adyacencia del nodo
	visited[node] = true;
	queue.push_back(node);
	list<int>::iterator i;
	cout << " - ";

	while (!queue.empty())
	 {
		node = queue.front();
		cout << node << " - ";
		queue.pop_front();

		for (i = adjList[node].begin(); i != adjList[node].end(); ++i)
			if (!visited[*i]) 
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
	}
}

void Graph::printMatrix()
{
	/* 
	Metodo que recorre la matriz de adyacencia y la imprime
	ENTRADA: n/a
	SALIDA: n/a
	COMPLEJIDAD: O(N^2)
	*/ 

	cout << "\n\nMatriz de adyacencia:\n\n    ";
	
	for (int i = 0; i < vertices; i++)
		cout << i << " ";
	cout << endl << "   ";

	for (int i = 0; i < vertices; i++)
		cout << "__";
	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << i << " | ";
		for (int j = 0; j < vertices; j++)
			cout << adjMatrix[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological 
	// Sort starting from all vertices one by one 
	for (int i = 0; i < vertices; i++)
		if (!visited[i])
			recursiveSort(i, visited, Stack);

	cout << "Ordenamiento: ";
	// Print contents of stack 
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
	cout << "\n";
}

bool Graph::Warshall(int source, int destination)
{
	/*
	Metodo que determina si existen conexiones directas entre nodos
	ENTRADA: numero del nodo fuente, numero del nodo destino
	SALIDA: boolean TRUE/FALSE
	COMPLEJIDAD: O(N^3)
	*/

	bool **auxm = adjMatrix;

	for (int k = 0; k < vertices; k++) // k sirve para verificar que haya un conexion
		for (int i = 0; i < vertices; i++) // i,j representan la iteracion en la matriz
			for (int j = 0; j < vertices; j++) 
				auxm[i][j] = auxm[i][j] or (auxm[i][k] and auxm[k][j]); // Regresa true si ya existe un 1 o si con ayuda de k encuentra una conexion en i o en j.

	if (auxm[source][destination])
		return true;
	else
		return false;
}

Graph::~Graph()
{
}

void Graph::listDFS(int node, bool visited[])
{
	/*
	Metodo que recorre recursivamente los nodos del grafo como pila, con la lista de adyacencia
	ENTRADA: node, lista visited[]
	SALIDA: n/a
	COMPLEJIDAD: O(N)
	*/

	list<int>::iterator i;
	visited[node] = true;
	cout << node << " - ";

	for (i = adjList[node].begin(); i != adjList[node].end(); ++i) // Recorre la lista de adyacencia del nodo
		if (!visited[*i]) // Si un nodo no ha sido visitado, lo visita
			listDFS(*i, visited);
}

void Graph::matrixDFS(int node, bool visited[])
{
	/*
	Metodo que recorre recursivamente los nodos del grafo como pila, con la matriz de adyacencia
	ENTRADA: node, lista visited[]
	SALIDA: n/a
	COMPLEJIDAD: O(N)
	*/

	visited[node] = true;
	cout << node << " - ";

	for (int i = 0; i < vertices; i++)
	{
		if (adjMatrix[node][i] == true && !visited[i])
			matrixDFS(i, visited);
	}
}

void Graph::recursiveSort(int v, bool visited[], stack<int>& Stack)
{
	// Mark the current node as visited. 
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i;
	for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
		if (!visited[*i])
			recursiveSort(*i, visited, Stack);

	// Push current vertex to stack which stores result 
	Stack.push(v);
}