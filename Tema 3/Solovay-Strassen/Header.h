#include <cmath>

// Funcție pentru a calcula (a^b) % m
int power(int a, unsigned int b, int m) {
    int result = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return result;
}

// Funcție pentru a calcula simbolul Jacobi
int jacobi(int a, int n) {
    if (n <= 0 || n % 2 == 0)
        return 0;
    int result = 1;
    if (a < 0) {
        a = -a;
        if (n % 4 == 3)
            result = -result;
    }
    while (a != 0) {
        while (a % 2 == 0) {
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5)
                result = -result;
        }
        int temp = a;
        a = n;
        n = temp;
        if (a % 4 == 3 && n % 4 == 3)
            result = -result;
        a %= n;
    }
    if (n == 1)
        return result;
    return 0;
}

// Funcție pentru a verifica dacă numărul este prim folosind algoritmul Solovay-Strassen
bool solovayStrassen(int p, int iterations) {
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;

    for (int i = 0; i < iterations; ++i) {
        int a = rand() % (p - 1) + 1;
        int jac = jacobi(a, p);
        int mod = power(a, (p - 1) / 2, p);
        if (jac == 0 || mod != jac)
            return false;
    }
    return true;
}