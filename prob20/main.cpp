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
#include <set>
#include <utility>
#include <vector>
#include <map>
#include "ConjuntosDisjuntos.h"

using namespace std;


using Posicion = pair<int, int>;


bool resuelveCaso() {
	int fila, col;
	char mNegra;
	cin >> fila;
	if (!cin)
		return false;
	cin >> col;

	cin.ignore();

	map<pair<int, int>, int> posMNegras;
	for (int i = 0; i < fila; ++i) {
		for (int j = 0; j < col; ++j) {
			cin.get(mNegra);

			if (mNegra == '#') {
				posMNegras.insert({ {i,j},int(posMNegras.size()) });
			}

		}cin.ignore();
	}
	int nuevas;
	cin >> nuevas;
	ConjuntosDisjuntos cjto(posMNegras.size() + nuevas);
	for (const auto& punto : posMNegras) {

		if (posMNegras.find({ punto.first.first - 1,punto.first.second }) != posMNegras.end()) {
			cjto.unir(punto.second, posMNegras[{punto.first.first - 1, punto.first.second }]);
		}
		if (posMNegras.find({ punto.first.first,punto.first.second - 1 }) != posMNegras.end()) {
			cjto.unir(punto.second, posMNegras[{ punto.first.first, punto.first.second - 1}]);
		}
		if (posMNegras.find({ punto.first.first - 1,punto.first.second - 1 }) != posMNegras.end()) {
			cjto.unir(punto.second, posMNegras[{punto.first.first - 1, punto.first.second - 1 }]);
		}
		if (posMNegras.find({ punto.first.first - 1,punto.first.second + 1 }) != posMNegras.end()) {
			cjto.unir(punto.second, posMNegras[{punto.first.first - 1, punto.first.second + 1 }]);
		}

	}

	int mayor_componente = 0;
	for (int i = 0; i < posMNegras.size(); ++i)
		mayor_componente = max(mayor_componente, cjto.cardinal(i));
		cout << mayor_componente << ' ';


	int f, c;
	for (int i = 0; i < nuevas; ++i) {
		cin >> f >> c;

		posMNegras.insert({ {f - 1,c - 1},int(posMNegras.size()) });
		if (posMNegras.find({ f - 1 - 1,c - 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 - 1, c - 1 }]);
		}
		if (posMNegras.find({ f - 1 + 1,c - 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 + 1, c - 1 }]);
		}
		if (posMNegras.find({ f - 1 ,c - 1 - 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1, c - 1 - 1}]);
		}
		if (posMNegras.find({ f - 1 ,c - 1 + 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1, c - 1 + 1}]);
		}
		if (posMNegras.find({ f - 1 - 1,c - 1 - 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 - 1, c - 1 - 1 }]);
		}
		if (posMNegras.find({ f - 1 + 1,c - 1 - 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 + 1, c - 1 - 1 }]);
		}
		if (posMNegras.find({ f - 1 - 1,c - 1 + 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 - 1, c - 1 + 1 }]);
		}
		if (posMNegras.find({ f - 1 + 1,c - 1 + 1 }) != posMNegras.end()) {
			cjto.unir(posMNegras[{ f - 1, c - 1 }], posMNegras[{ f - 1 + 1, c - 1 + 1 }]);
		}
		mayor_componente = max(mayor_componente, cjto.cardinal(posMNegras[{ f - 1, c - 1 }]));
		cout << mayor_componente << ' ';



	}
	cout << '\n';

	posMNegras.clear();
	return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("entrada.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
