//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "queue_eda.h"
#include "Grafo.h"

using namespace std;



int bfs(Grafo G, int s, vector<bool>& marked)
{
	vector<bool> vigilados(G.V(), false);
	int tamComp = 1, numGuardias = 0;

	queue<int> cola;

	marked[s] = true; // Mark the source
	cola.push(s); // and put it on the queue.
	while (!cola.empty())
	{
		int v = cola.front(); // Remove next vertex from the queue.
		cola.pop();
		for (int w : G.ady(v)) {
			if (!marked[w]) // For every unmarked adjacent vertex,
			{
				tamComp++;
				marked[w] = true; // mark it because path is known,
				cola.push(w); // and add it to the queue.

				if (!vigilados[v]) {
					vigilados[w] = true;
					++numGuardias;
				}
			}
			else if (vigilados[w] && vigilados[v])
				return -1;

			// La calle no está vigilada
			else if (!vigilados[w] && !vigilados[v])
				return -1;
		}

	}
	//cout << "tamcomp: "<<tamComp << endl;
	return std::min(numGuardias, tamComp - numGuardias );
}

bool resuelveCaso() {
	int N, V;
	cin >> N >> V;
	if (!cin)
		return false;
	vector<bool> marked(N, false);
	Grafo G(N);

	int a, b;
	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		G.ponArista(a - 1, b - 1);
	}

	int sumaGuardias = 0;
	int numGuardiasComp = 0;
	
	for (int i = 0; i < N && numGuardiasComp != -1; ++i) {
		if (!marked[i]) {
			numGuardiasComp = bfs(G, i, marked);
			sumaGuardias += numGuardiasComp;
		}

	}

	if (numGuardiasComp == -1)
		std::cout << "IMPOSIBLE\n";
	else
		std::cout << sumaGuardias << '\n';


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