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


// resuelve un caso de prueba
/*bool resuelveCaso() {
	int p;
	cin >> p;
	if (!cin)
		return false;
	int n;
	cin >> n;
	PriorityQueue<int, greater<int>> distrib;
	int extra = p - n;
	int pPorIns;
	for (int i = 0; i < n; ++i) {
		cin >> pPorIns;
		distrib.push(pPorIns);
	}
	int m,mitad;

	for (int i = 0; i < extra; ++i) {

		m = distrib.top();
		distrib.pop();
		mitad=m / 2;
		distrib.push(mitad);
		distrib.push(m-mitad);

	}

	cout << distrib.top() << '\n';
	distrib.pop();
	cout << distrib.top() << endl;
	cout << endl;
	return true;
}*/


struct Atril {
	int numMusicos;
	int partituras;
};

bool operator >(Atril const& a1, Atril const& a2) {
	int grupos1 = a1.numMusicos / a1.partituras;
	int grupos2 = a2.numMusicos / a2.partituras;

	if (a1.numMusicos % a1.partituras != 0)
		grupos1++;
	if (a2.numMusicos % a2.partituras != 0)
		grupos2++;

	return grupos1 > grupos2;
}


bool resuelveCaso() {
	int n, p;

	cin >> p >> n;

	if (!cin)  // fin de la entrada
		return false;

	PriorityQueue<Atril, greater<Atril>> musicos;
	int m;

	for (int i = 0; i < n; i++) {
		cin >> m;
		//todos los grupos empiezan con una partitura
		musicos.push({ m,1 });
	}

	p -= n;

	//mientras queden partituras
	Atril a;
	while (p > 0) {
		musicos.pop(a);
		a.partituras++;
		p--;
		musicos.push(a);
	}

	a = musicos.top();
	int sol = a.numMusicos / a.partituras;
	if (a.numMusicos % a.partituras != 0)
		sol++;

	cout << sol << "\n";

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