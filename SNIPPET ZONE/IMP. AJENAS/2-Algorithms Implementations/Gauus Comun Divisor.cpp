/*
Luis Enrique Bernal Fuentes
Algorithm: Gauus Comun Divisor
Descriptions: Sirve para hallar el M�ximo Com�n Divisor entre dos n�meros
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	while (a) {
		swap (a, b);
		a %= b;
	}
	return b;
}

int a, b;

int main() {
	scanf ("%d %d", &a, &b);
	
	printf ("MCD es %d\n", GCD (a, b));
	printf ("MCM es %d\n", a * b / GCD (a, b));
	system("pause > nul");
	return 0;
}
