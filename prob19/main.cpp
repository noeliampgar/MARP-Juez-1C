//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream> 
#include <vector>  
#include <limits.h>
#include <limits>
#include "queue_eda.h"
#include <unordered_map>



using namespace std;

int MAX = 10000;
int INF = 100000000;
int adyacente(int v, int i, vector<int> const& serpientes, vector<int> const& escaleras) {
	int ady = v + i;

	if (serpientes[ady] != 0)
		ady = serpientes[ady];

	else if (escaleras[ady] != 0)
		ady = escaleras[ady];


	return ady;
}

int bfs(int const& origen, int const& destino, vector<int> const& serpientes, vector<int> const& escaleras) {
	if (origen == destino) return 0;


	vector<int> distancia(destino+1, INF);
	distancia[origen] = 0;
	queue<int> cola; cola.push(origen);
	while (!cola.empty()) {
		int v = cola.front(); cola.pop();
		for (int i = 1; i <= 6; ++i) {
			int w = adyacente(v, i, serpientes, escaleras);
			if (distancia[w] == INF) {
				distancia[w] = distancia[v] + 1;
				if (w == destino) return distancia[w];
				else cola.push(w);
			}

		}
	}
}

/*bool resuelveCaso() {
	int dimT, numCaras, numS, numE;

	cin >> dimT >> numCaras >> numS >> numE;
	if (!dimT && !numCaras && !numS && !numE) return false;

	int dim = dimT * dimT;

	vector<int> serpientes(dim, 0);
	vector<int> escaleras(dim, 0);

	int sIni, sFin;
	for (int i = 0; i < numS; ++i) {
		cin >> sIni >> sFin;
		serpientes[sIni-1] = sFin-1;

	}
	int eIni, eFin;

	for (int i = 0; i < numE; ++i) {
		cin >> eIni >> eFin;
		escaleras[eIni-1] = eFin-1;

	}
	//cout <<escaleras[5]<< '\n';

	cout << bfs(0, dim-1, serpientes, escaleras) << '\n';
	return true;
}*/
bool resuelveCaso() {
	int n, k, s, e;
	cin >> n >> k >> s >> e;
	if (n == 0 && k == 0 && s == 0 && e == 0)
		return false;

	unordered_map<int, int> serEscaleras;
	int val1, val2;
	int tablero[10000];
	for (int i = 0; i < n * n; i++) tablero[i] = n * n;

	for (int i = 0; i < s + e; i++)
	{
		cin >> val1 >> val2;
		serEscaleras[val1 - 1] = val2 - 1;
	}


	vector<int> dentro, fuera;
	tablero[0] = 0;
	fuera.push_back(0);
	int ciclo = 0;
	int niSerpNiEscalera;

	while (true) {
		ciclo++;
		while (!fuera.empty()) {
			int act = fuera.back();
			fuera.pop_back();
			niSerpNiEscalera = -1;

			for (int j = 0; j < k; j++)
			{
				int pos = act + 1 + j;
				if (pos == n * n - 1) goto salida;
				else if (tablero[pos] > ciclo)
				{

					if (serEscaleras.count(pos)) {
						tablero[serEscaleras[pos]] = ciclo;
						dentro.push_back(serEscaleras[pos]);
					}
					else niSerpNiEscalera = pos;

					tablero[pos] = ciclo;
				}
			}

			if (niSerpNiEscalera != -1) dentro.push_back(niSerpNiEscalera);
		}

		fuera = dentro;
		while (!dentro.empty()) dentro.pop_back();
	}

salida: cout << ciclo << '\n';
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