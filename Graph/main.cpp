// main.cpp
// Carlos G. Olivas Cordova / A01246040
// Andrick J. Perez Landa / A01434206

#include <list>
#include <algorithm>
#include <iostream>
#include "Graph.h"

int main()
{
	int numeroNodos = 5;
	Graph g(numeroNodos);

	cout << "\nConstruyendo el grafo con " << numeroNodos << " nodos\n";
	
	/*g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	*/
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 0);
	
	cout << "\nRecorrido en profundidad DSF\n";
	g.DFS(0);

	cout << "\nRecorrido en anchura BSF\n";
	g.BFS(0);

	g.printMatrix();

	g.topologicalSort();

	int n1, n2;
	cout << "Introduzca dos nodos para saber si existe una conexion entre el primero y el segundo\n";
	cin >> n1;
	cin >> n2;

	if (g.Warshall(n1, n2))
		cout << "TRUE: Existe una conexion entre ambos nodos" << endl;
	else
		cout << "FALSE: No se encontro una conexion" << endl;

}