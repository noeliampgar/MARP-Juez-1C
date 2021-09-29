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
struct tarea {
	int ini;
	int fin;
	int periodo;
};


struct	OrdT {
	bool	operator()(tarea	const& p1, const tarea& p2) const {
		return	(p1.ini < p2.ini) || ((p1.ini == p2.ini) && (p1.fin < p2.fin));
	}
};


// resuelve un caso de prueba
bool resuelveCaso() {
	int nTU, nTP;
	cin >> nTU;
	if (!cin)
		return false;
	cin >> nTP;

	int minutos;
	cin >> minutos;
	PriorityQueue<tarea, OrdT> tareas;
	bool noSolapa = true;
	tarea tr; int ini, fin;
	for (int i = 1; i <= nTU; ++i) {
		cin >> ini >> fin;
		if (ini < minutos) {
			tr.ini = ini;
			if (fin < minutos)
				tr.fin = fin;
			else
				tr.fin = minutos;
			tr.periodo = -1;
			tareas.push(tr);
		}
	}

	int periodo;
	for (int i = 1; i <= nTP; ++i) {
		cin >> ini >> fin >> periodo;
		if (ini < minutos) {
			tr.ini = ini;
			if (fin < minutos)
				tr.fin = fin;
			else
				tr.fin = minutos;
			tr.periodo = periodo;

			tareas.push(tr);

		}
	}

	tarea actual, sig;
	while (!tareas.empty() && noSolapa) {
		tareas.pop(actual); //cout << actual.ini << ' ' << actual.fin << endl;
		if (actual.periodo != -1 && actual.ini + actual.periodo < minutos) {
			tr.ini = actual.ini + actual.periodo;

			if (actual.fin + actual.periodo < minutos)
				tr.fin = actual.fin + actual.periodo;
			else
				tr.fin = minutos;

			tr.periodo = actual.periodo;

			tareas.push(tr);
		}
		if (!tareas.empty()) {
			sig = tareas.top(); //cout << sig.ini << ' ' << sig.fin << endl;
			if (sig.ini < actual.fin)
				noSolapa = false;

		}
	}



	if (noSolapa)cout << "NO" << endl;
	else cout << "SI" << endl;

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