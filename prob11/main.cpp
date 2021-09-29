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

void dfs(Grafo const & G, int   v, vector<bool>& marked, int& nV)
{
	nV++;
	marked[v] = true;
	for (int w : G.ady(v))
		if (!marked[w])
		{
			dfs(G, w, marked, nV);
		}
}



int numAmigos(Grafo G) {
	int N = G.V();
	vector<bool> marked(N, false);
	int maxAmigos = 0;
	for (int i = 1; i < N && maxAmigos<N-maxAmigos; ++i) {
		if (!marked[i]) {
			int nV = 0;
			dfs(G, i, marked, nV);
			if (nV > maxAmigos) maxAmigos = nV;

		}



	}
	return maxAmigos;
}


void resuelveCaso() {
	int V, E;
	cin >> V >> E;

	Grafo G(V+1);
	int a, b;

	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		G.ponArista(a, b);
	}
	
	int sol = numAmigos(G);
	cout << sol << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}




