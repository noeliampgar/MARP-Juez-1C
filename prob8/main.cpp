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
bool resuelveCaso() {
	int nEv;
	cin >> nEv;
	if (!cin)
		return false;
	PriorityQueue <int>cola2;
	PriorityQueue <int, std::greater<int>>cola1;

	int eve;

	int n = 0, mediana;
	for (int i = 1; i <= nEv; ++i) {
		cin >> eve;
		if (eve == 0) {
			if (n == 0) {
				if (i == nEv)
					cout << "ECSA\n";
				else
					cout << "ECSA ";
			}
			else {
				if (i == nEv)
					cout << mediana << '\n';
				else
					cout << mediana << ' ';
				if (n % 2 == 0) {
					cola1.pop();
					if(n>1)
						mediana = cola2.top();
				}
				else {
					cola2.pop();
					if(n>1)
						mediana = cola1.top();
				}
				n--;
			}
		}
		else {
			if (n == 0) {
				cola2.push(eve);
				mediana = eve;

			}
			else {
				if ((n + 1) % 2 == 0) {
					if (eve > cola2.top()) {
						cola2.push(eve);
						cola1.push(cola2.top());
						cola2.pop();
					}
					else cola1.push(eve);
					mediana = cola1.top();
				}
				else {
					if (eve > cola2.top()) cola2.push(eve);
					else {
						cola1.push(eve);
						cola2.push(cola1.top());
						cola1.pop();
					}
					mediana = cola2.top();
				}
			}
			n++;
		}
	}
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