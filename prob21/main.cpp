//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

ConjuntosDisjuntos resolver(GrafoValorado<int>& gv, vector<Arista<int>>& aristas, int V, int anchura) {
	ConjuntosDisjuntos conjuntos(V);
	for (Arista<int> a : aristas) {
		if (a.valor() >= anchura && !conjuntos.unidos(a.uno(), a.otro(a.uno())))
			conjuntos.unir(a.uno(), a.otro(a.uno()));
	}
	return conjuntos;
}

bool resuelveCaso() {
	int V, E;
	cin >> V >> E;

	if (!cin) return false;

	GrafoValorado<int> gv(V);
	vector<Arista<int>> aristas;
	int V1, V2, anchuraMax;
	for (int i = 0; i < E; ++i) {
		cin >> V1 >> V2 >> anchuraMax;
		Arista<int> a(V1 - 1, V2 - 1, anchuraMax);
		gv.ponArista(a);
		aristas.push_back(a);
	}

	int K;
	cin >> K;

	int origen, destino, anchura;
	for (int i = 0; i < K; ++i) {
		cin >> origen >> destino >> anchura;
		ConjuntosDisjuntos conjuntos = resolver(gv, aristas, V, anchura);
		cout << (conjuntos.unidos(origen - 1, destino - 1) ? "SI\n" : "NO\n");
	}

	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("entrada.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
#endif
	return 0;
}