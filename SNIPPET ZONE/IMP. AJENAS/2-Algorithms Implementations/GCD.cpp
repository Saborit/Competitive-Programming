/*
Luis Enrique Bernal Fuentes
Algorithm: GCD
(Sirve para hallar el MCD entre dos números)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int mcd(int a, int b) {
	while (a) {
		swap (a, b);
		a %= b;
	}
	return b;
}

int a, b;

int main() {
	scanf ("%d %d", &a, &b);
	
	mcd(a, b);
	
	printf ("%d", mcd(a, b));
	
	system("pause > nul");
	return 0;
}
