#include <iostream>
#include <cstdlib>
#include <cmath>
#include"Header.h";

using namespace std;

int main() {
    int numar = 80929;
    int iteratii = 10; // Numărul de iterații

    if (solovayStrassen(numar, iteratii))
        cout << numar << " este probabil prim." << endl;
    else
        cout << numar << " este compus." << endl;

    return 0;
}
