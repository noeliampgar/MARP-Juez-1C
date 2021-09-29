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



long int costeSuma(PriorityQueue<long int> cola) {
	long int contCoste = 0, suma = 0;
	long int ult;


	while (cola.size() >= 2) {
		cola.pop(ult);
		suma = ult;
		cola.pop(ult);
		suma += ult;
		contCoste += suma;

		if ((!cola.empty()))cola.push(suma);


	}


	return contCoste;
}


// resuelve un caso de prueba
bool resuelveCaso() {
	int nNums; cin >> nNums;
	//cout << "hola" << endl;
	if (nNums == 0)
		return false;

	PriorityQueue<long int> cola;
	int num;
	for (int i = 0; i < nNums; ++i) {
		//cout << "for" << endl;

		cin >> num;
		cola.push(num);


	}		cout << costeSuma(cola) << endl;

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