//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>

#include "ConjuntosDisjuntos.h"
using namespace std;




bool resuelveCaso() {
	int N, numG;
	cin >> N;

	if (!cin)
		return false;
	ConjuntosDisjuntos cjto(N);

	cin >> numG;
	for (int i = 0; i < numG; ++i) {
		int numP, p, pAnt;
		cin >> numP;
		for (int j = 0; j < numP; ++j) {
			cin >> p;
			if(j>0)
			cjto.unir(pAnt-1, p-1);
			pAnt = p;

		}

	}


	for (int i = 0; i < N; ++i) {
		cout << cjto.cardinal(i) << ' ';


	}
	cout << '\n';
	return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}