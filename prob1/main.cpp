#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include "bintree_eda.h"


using namespace std;





bool esBalanceadoAux(bintree<int> const& a, int& talla, int& maxIz, int& minDr) {//Parámetro por referencia pq  la infomración viene desde mis hijos
	//cout << "talla1-> " << talla << '\n';
	if (a.empty()) {
		talla = 0;
		
		return true;
	}
	else {
		int tallaiz = 0, talladr = 0; int maxIzIz = INT_MIN, minDrIz = INT_MIN, maxIzDr = INT_MAX, minDrDr = INT_MAX;
		if (esBalanceadoAux((a.left()), tallaiz, maxIzIz, minDrIz) && esBalanceadoAux((a.right()), talladr, maxIzDr, minDrDr)) {
			talla = max(tallaiz, talladr) + 1;	//cout << "talla1-> " << talla << '\n';
			bool may = true; bool men = true;
			if (!a.left().empty()){
				maxIz = max(max(maxIzIz, minDrIz), a.left().root());
			    may = a.root() > maxIz;
			}
			
			
			if (!a.right().empty()){
				minDr = min(min(maxIzDr, minDrDr), a.right().root());
				men = a.root() < minDr;
			}


			return may && men && abs(tallaiz - talladr) <= 1;

		}
		else
			return false;
	}

}


bool esBalanceado(bintree<int> const& a) {
	int talla = 0, c = 0, b = 0;
	return esBalanceadoAux(a, talla,c,b);


}



// resuelve un caso de prueba
void resuelveCaso() {
	//bintree<char> arbol;
	auto arbol = leerArbol(-1);

	if (esBalanceado(arbol))
		cout << "SI\n";
	else cout << "NO\n";


}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}












//(*   (*(*(*..)(*(*.(*..))(*..)))(*(*(*..)(*..))(*..)))    (*(*(*..)(*(*..)(*..))).)):6
