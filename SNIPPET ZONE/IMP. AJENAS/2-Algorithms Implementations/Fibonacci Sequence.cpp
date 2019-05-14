/*
Luis Enrique Bernal Fuentes
Algorithm: Fibomacci Sequence
Description: Halla el número de la Secuencia Fibonaci que cae en tal posición. 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long a = 0, b = 1, fib;

int main() {
	scanf ("%d", &n);
	
	if (n <= 2)
		printf ("1\n");
	else {
		for (int i = 3; i <= n; i++) {
			fib = a + b;
			a = b;
			b = fib;
		}
		printf ("%I64d\n", fib);
	}

    system ("pause > nul");
	return 0;
}
