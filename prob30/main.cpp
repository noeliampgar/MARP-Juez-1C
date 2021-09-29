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


int min(std::vector<int> const& personas, std::vector<int> const& esquis) {
    int suma = 0;
    for (int i = 0; i < personas.size(); ++i) {
        suma += abs(personas[i] - esquis[i]);
    }
    return suma;
}

bool resuelveCaso() {
    int N;
    std::cin >> N;

    if (N == 0) return false;

    std::vector<int> personas(N), esquis(N);
    for (int i = 0; i < N; ++i) std::cin >> personas[i];
    for (int i = 0; i < N; ++i) std::cin >> esquis[i];
    sort(personas.begin(), personas.end());
    sort(esquis.begin(), esquis.end());

    std::cout << min(personas, esquis) << '\n';

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
