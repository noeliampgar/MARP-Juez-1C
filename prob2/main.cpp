//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "bintree_eda.h"
#include "TreeSet_AVL.h"


using namespace std;



// resuelve un caso de prueba
bool resuelveCaso() {
	int numElems;
	cin >> numElems;

	if (numElems == 0)
		return false;
	Set <int> cj;
	int elem, numPos, posiciones;
	for (int i = 0; i < numElems; ++i) {
		cin >> elem;
		cj.insert(elem);

	}

	cin >> numPos;
	for (int i = 0; i < numPos; ++i) {
		cin >> posiciones;

		try {
			cout << cj.kesimo(posiciones) << endl;
		}
		catch (ENumElemsMenorQueK) {
			cout << "??" << endl;


		}
	}


	cout << "---" << endl;

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