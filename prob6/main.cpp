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
struct caja {


	int num;
	int time;


};


struct	OrdC {
	bool	operator()(caja	const& p1, caja& p2) {
		return	(p1.time < p2.time) || ((p1.time == p2.time) && p1.num < p2.num);
	}
};







// resuelve un caso de prueba
bool resuelveCaso() {
	int nPer, nCajas;
	cin  >> nCajas>> nPer;
	if (nPer == 0 && nCajas == 0)
		return false;

	PriorityQueue<caja, OrdC> cajas;
	caja cj;
	for (int i = 1; i <= nCajas; ++i) {
		cj.num = i;
		cj.time = 0;

		cajas.push(cj);

	}

	int tiempo;
	for (int i = 0; i < nPer; ++i) {
		cin >> tiempo;
		cj = cajas.top();
			cajas.pop();
		cj.time += tiempo;
		cajas.push(cj);

	}

	cout << cajas.top().num<<'\n';

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