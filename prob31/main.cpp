//Noelia Pérez García-Consuegra
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <fstream>  
#include <limits.h>
#include <limits>
#include <climits>

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct hotel {
    int inicio, fin;
};

bool ordenar(hotel const& h1, hotel const& h2) {
    return h1.fin < h2.fin || (h1.fin == h2.fin && h1.inicio < h2.inicio);
}

int tuneles(std::vector<hotel> hoteles) {
    int tuneles = 0, inicio = 0, fin = 0;

    int i = 0;
    while (i < hoteles.size()) {
        inicio = hoteles[i].inicio;
        fin = hoteles[i].fin;
        ++i;
        while (i < hoteles.size() && hoteles[i].inicio < fin) {
            if (inicio < hoteles[i].inicio) inicio = hoteles[i].inicio;
            if (fin > hoteles[i].fin) fin = hoteles[i].fin;
            ++i;
        }
        tuneles++;
    }

    return tuneles;
}

bool resuelveCaso() {
    int N;
    std::cin >> N;

    if (N == 0) return false;

    std::vector<hotel> hoteles(N);
    for (int i = 0; i < N; ++i) std::cin >> hoteles[i].inicio >> hoteles[i].fin;
    std::sort(hoteles.begin(), hoteles.end(), ordenar);

    std::cout << tuneles(hoteles) << '\n';

    return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
/**/#ifndef DOMJUDGE
	ifstream in("entrada.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif/**/
	return 0;
}
