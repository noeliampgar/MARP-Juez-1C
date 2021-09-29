//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "PriorityQueue.h"


using namespace std;
struct dtrio {


	long long int id;
	int tIni;
	int t;

};


struct	OrdDst {
	bool	operator()(dtrio	const& d1, dtrio	const& d2) {
		return	(d1.t < d2.t) || ((d1.t == d2.t) && (d1.id < d2.id));
	}
};




void aQuienVa(int numEnvios, PriorityQueue<dtrio, OrdDst> cola) {

	for (int i = 0; i < numEnvios; ++i) {
		dtrio prim;
		cola.pop(prim);
		cout << prim.id << "\n";
		prim.t += prim.tIni;
		cola.push(prim);


	}

}


// resuelve un caso de prueba
bool resuelveCaso() {
	int nNums; cin >> nNums;
	if (nNums == 0)
		return false;

	PriorityQueue<dtrio, OrdDst> cola;
	dtrio dest;
	for (int i = 0; i < nNums; ++i) {

		cin >> dest.id >> dest.tIni;
		dest.t = dest.tIni;
		cola.push(dest);


	}
	int numEnvios;
	cin >> numEnvios;


	aQuienVa(numEnvios, cola);
	cout << "---" << "\n";

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