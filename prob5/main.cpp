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
struct paciente {


	 string id;
	int priority;
	int tiempo;
	

};


struct	OrdP {
	bool	operator()(paciente	const& p1, paciente	const& p2) {
		return	(p1.priority > p2.priority) || ((p1.priority == p2.priority) && p1.tiempo<p2.tiempo);
	}
};







// resuelve un caso de prueba
bool resuelveCaso() {
	int nEventos; cin >> nEventos;
	if (nEventos == 0)
		return false;

	PriorityQueue<paciente, OrdP> cola;
	char letra; paciente pac;
	for (int i = 0; i < nEventos; ++i) {
		cin >> letra;
		if (letra == 'I') {
			cin >> pac.id >> pac.priority;
			pac.tiempo = i;
			cola.push(pac);

		}

		else if (letra == 'A') {


			cout << cola.top().id << '\n';
			cola.pop();

		}/**/
		
	}



	
	cout << "---" << "\n";

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