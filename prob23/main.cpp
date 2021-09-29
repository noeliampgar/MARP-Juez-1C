//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>

#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"


using namespace std;


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) // fin de la entrada
		return false;
	vector<int> carga;
	int val, m;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		carga.push_back(val);
	}
	cin >> m;
	int ini, fin;
	DigrafoValorado<int> g(n);
	for (int j = 0; j < m; ++j) {
		cin >> ini >> fin >> val;
		g.ponArista(AristaDirigida<int>(ini - 1, fin - 1, val));
	}
	vector<AristaDirigida<int>> aristaTo(n);
	vector<int> distTo(n, INT_MAX);
	IndexPQ <int> pq(n);
	distTo[0] = carga[0];
	pq.push(0, carga[0]);

	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> a : g.ady(v)) {
			int v1 = a.desde(); int v2 = a.hasta();
			if (distTo[v2] > distTo[v1] + a.valor() + carga[v2]) {
				distTo[v2] = distTo[v1] + a.valor() + carga[v2];
				aristaTo[v2] = a;
				pq.update(v2, distTo[v2]);
			}
		}
	}
	if (distTo[n - 1] == INT_MAX) cout << "IMPOSIBLE\n";
	else cout << distTo[n - 1] << '\n';
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
