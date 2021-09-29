//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream> 
#include <vector>  
#include <limits.h>
#include <limits>
#include "Digrafo.h"


using namespace std;


bool resuelveCaso() {
	int V, E;
	cin >> V >> E;
	if (!cin)
		return false;	Digrafo G(V);

	int a, b;
	for (int i = 0; i < E; ++i) {

		cin >> a >> b;
		G.ponArista(a , b );
	}


	vector<int> vEntradas(G.V(), 0);
	int sumi = false; int vSumi=0;
	for (int i = 0; i < G.V() && !sumi; ++i) {

		for (int j = 0; j < G.ady(i).size() && !sumi; ++j) {
			int n = G.ady(i)[j];
			vEntradas[n]++;
			if (vEntradas[n] == G.V() - 1 && G.ady(n).size() == 0) {
				sumi = true;
				vSumi = n;
			}
		}
	}/**/

	if (sumi)
		cout << "SI " << vSumi << '\n';
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