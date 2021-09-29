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



struct hora {
    int horas;
    int minutos;
};

struct pelicula {
    hora inicio;
    hora fin;
    int duracion;
};


// funciones *hora*
hora operator+(hora const& h, int const& m) {
    hora _h = h;
    _h.minutos += m;
    while (_h.minutos >= 60) {
        _h.minutos -= 60;
        ++_h.horas;
    }
    return _h;
}

bool operator<(hora const& a, hora const& b) {
    return (a.horas < b.horas) || (a.horas == b.horas && a.minutos < b.minutos);
}

bool operator==(hora const& a, hora const& b) {
    return a.horas == b.horas && a.minutos == b.minutos;
}


// funciones *peliculas*
bool ordenar(pelicula const& p1, pelicula const& p2) {
    return p1.fin < p2.fin || (p1.fin == p2.fin && p2.inicio < p1.inicio);
}


// funciones *problema*
int maxPeliculas(std::vector<pelicula> const& cartelera) {
    pelicula ultimaPelicula = cartelera[0];
    int max = 1;
    for (int i = 1; i < cartelera.size(); ++i) {
        if (ultimaPelicula.fin + 9 < cartelera[i].inicio) {
            ultimaPelicula = cartelera[i];
            max++;
        }
    }
    return max;
}

bool resuelveCaso() {
    int N;
    std::cin >> N;

    if (N == 0) return false;

    std::vector<pelicula> cartelera(N);
    hora h;
    char aux;

    for (int i = 0; i < N; ++i) {
        std::cin >> h.horas >> aux >> h.minutos >> cartelera[i].duracion;
        cartelera[i].inicio = h;
        cartelera[i].fin = cartelera[i].inicio + cartelera[i].duracion;
    }

    sort(cartelera.begin(), cartelera.end(), ordenar);

    std::cout << maxPeliculas(cartelera) << '\n';

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
