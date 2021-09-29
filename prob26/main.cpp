//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include <climits>

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool resuelveCaso() {
    int nAguj,lParches;
	cin >> nAguj >> lParches;

    if (!cin) return false;
	int nParches = 0, ultCubre = 0;
	int posicion;
	cin >> posicion;
	nParches++;
	ultCubre = posicion + lParches ;
	for (int i = 1; i < nAguj; ++i) { 

		cin >> posicion;
		if (ultCubre < posicion) {
			nParches++;
			ultCubre = posicion + lParches ;
		}

	
	
	}

    cout <<nParches << '\n';

    return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
/**/#ifndef DOMJUDGE
	ifstream in("entrada.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif/**/
	return 0;
}
