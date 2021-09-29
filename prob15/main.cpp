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

using namespace std;





void bfs(Grafo const& g, int s, vector<bool> &marked,vector<int> &distTo)
{
	//creamos la cola e inicializamos el nodo de origen a 0 de distancia y lo marcamos y metemos en la cola
	queue<int> q;
	distTo[s] = 0;
	marked[s] = true;
	q.push(s);

	//mientras la cola no este vacia
	while (!q.empty())
	{
		//extraemos el primer nodo de la cola
		int v = q.front();
		q.pop();
		//recorremos sus adyacentes
		for (int w : g.ady(v))
		{
			//si no estan marcados
			if (!marked[w])
			{
				//se marcan y se pone su distancia a la de su padre mas uno y se añade a la cola para recorrer los adyacentes de este
				distTo[w] = distTo[v] + 1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

int NodosLejanos(Grafo const& g, int origen, int TTL)
{
	vector<bool> marked(g.V(), false);
	vector<int> distTo(g.V(), 0);

	//calulamos las distancias entre nodos desde el origen
	bfs(g, origen, marked, distTo);
	//inicializamos los nodos que se encunetran en el rango TTL al numero de nodos del grafo
	int alcanzables = g.V();

	for (int i = 0; i < g.V(); i++)
	{
		//Si un nodo esta marcado y su distancia se encunetra en el rango de TTL, se resta uno
		if (marked[i] && distTo[i] <= TTL)
		{
			--alcanzables;
		}
	}
	return alcanzables;
}



/*void dfs(Grafo G, int v, vector<bool>& marked,
	int& nV, int TTL, vector<bool>& falta)
{
	if (marked[v] == false)
	{
		marked[v] = true; nV++;
	}

	marked[v] = true;
	if (TTL > 0) {
		for (int w : G.ady(v)) {
			if (!marked[w])
			{
				dfs(G, w, marked, nV, TTL - 1, falta);

			}
			else if (falta[w]) {
				falta[w] = false;
				dfs(G, w, marked, nV, TTL - 1, falta);
			}

		}
	}
	else {
		falta[v] = true;

	}

}*/

bool resuelveCaso() {
	int N, V;
	cin >> N >> V;
	if (!cin)
		return false;
	Grafo G(N);



	int a, b;

	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		G.ponArista(a - 1, b - 1);
	}
	int consultas, TTL, ini;
	cin >> consultas;
	for (int i = 0; i < consultas; ++i) {
		cin >> ini >> TTL;
		cout << NodosLejanos(G,ini-1,TTL) << '\n';

	}
	cout << "---\n";


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