//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream> 
#include <vector>  
#include <limits.h>
#include <limits>
#include "deque_eda.h"
#include "Digrafo.h"


using namespace std;

/*void dfs(Digrafo G, int v, vector<bool>& marked, deque<int>& reversePostorder, vector<bool>& marked2, bool& ciclo)
{
	marked2[v] = true;
	marked[v] = true;
	for (int w : G.ady(v)) {
		if (marked2[w]) {
			ciclo = true;
			break;
		}
		if (!marked[w] && !ciclo) dfs(G, w, marked, reversePostorder, marked2, ciclo);
	}
	reversePostorder.push_front(v);
	marked2[v] = false;


}
bool resuelveCaso()
{
	int V, E;
	cin >> V >> E;
	if (!cin)
		return false;
	Digrafo G(V);

	int a, b;
	for (int i = 0; i < E; ++i) {

		cin >> a >> b;
		G.ponArista(a - 1, b - 1);
	}

	vector<bool> marked(G.V(), false);
	deque<int> reversePostorder;
	bool ciclo = false;

	for (int v = 0; v < G.V(); v++) {
		vector<bool> marked2(G.V(), false);

		if (!marked[v]) dfs(G, v, marked, reversePostorder, marked2, ciclo);
	}
	if (!ciclo) {
		while (!reversePostorder.empty() && reversePostorder.size() > 1) {
			cout << reversePostorder.front() + 1 << ' ';
			reversePostorder.pop_front();


		}
		if (!reversePostorder.empty() && reversePostorder.size() == 1) {
			cout << reversePostorder.front() + 1 << '\n';
			reversePostorder.pop_front();
		}

	}
	else
		cout << "Imposible\n";
	return true;
}
*/





void dfs(Digrafo const& g, int v, vector<bool>& visit, deque <int>& orden, vector<bool>& visitVuelta, bool& ciclo) {
	visit[v] = true;
	visitVuelta[v] = true;

	for (int i = 0; i < g.ady(v).size() && !ciclo; ++i) {
		int w = g.ady(v)[i];
		if (visitVuelta[w]) {
			ciclo = true;
		}
		if (!visit[w] && !ciclo)
			dfs(g, w, visit, orden, visitVuelta, ciclo);
	}
	orden.push_front(v);
	visitVuelta[v] = false;

}



bool resuelveCaso() {
	int V, E;
	cin >> V >> E;
	if (!cin)
		return false;	Digrafo G(V);

	int a, b;
	for (int i = 0; i < E; ++i) {

		cin >> a >> b;
		G.ponArista(a - 1, b - 1);
	}



	deque<int> orden;
	vector<bool> visit(G.V(), false);
	bool ciclo = false;

	for (int v = 0; v < G.V() && !ciclo; ++v) {
		vector<bool> visitVuelta(G.V(), false);
		if (!visit[v])
			dfs(G, v, visit, orden, visitVuelta, ciclo);
	}

	if (ciclo)
		cout << "Imposible\n";
	else {
		while (!orden.empty() && orden.size() > 1) {
			cout << orden.front() + 1 << ' ';
			orden.pop_front();


		}
		if (!orden.empty() && orden.size() == 1) {
			cout << orden.front() + 1 << '\n';
			orden.pop_front();
		}

	}
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