//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "Grafo.h"
#include "queue_eda.h"

using namespace std;



void bfs(Grafo G, int s, vector<bool>& marked, vector<int>& edgeTo, int& numVisitados)
{
	queue<int> cola;
	numVisitados++;
	marked[s] = true; // Mark the source
	cola.push(s); // and put it on the queue.
	while (!cola.empty())
	{
		int v = cola.front(); // Remove next vertex from the queue.
		cola.pop();
		for (int w : G.ady(v))
			if (!marked[w]) // For every unmarked adjacent vertex,
			{
				edgeTo[w] = v; // save last edge on a shortest path,
				marked[w] = true; // mark it because path is known,
				numVisitados++;
				cola.push(w); // and add it to the queue.
			}
	}
}

bool resuelveCaso() {
	int N, V;
	cin >> N >> V;
	if (!cin)
		return false;
	vector<bool> marked(N, false);
	vector<int> edgeTo(N, -1);
	Grafo G(N);



	int a, b;

	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		G.ponArista(a, b);
	}
	bool arbol = N - V == 1;
	if (arbol) {
		int numVisitados = 0;
		bfs(G, 0, marked, edgeTo, numVisitados);
		//cout << numVisitados << endl;
		arbol = numVisitados == G.V();
	}
	if (arbol)
		cout << "SI\n";

	else
		cout << "NO\n";


	return true;

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
/**/#ifndef DOMJUDGE
	std::ifstream in("entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif/**/
	return 0;
}