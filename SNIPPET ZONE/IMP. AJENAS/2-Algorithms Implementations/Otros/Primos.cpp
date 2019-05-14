/*
Luis Enrique Bernal Fuentes
Algorithm: Primo 
Description: Sirve para decir si un número es primo o no para p > 3
		    Primo (6k + 1 && 6k - 1)
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int p;

bool Prim (int p) {
	if (p % 6 != 1 && p % 6 != 5)
		return false;
	
	int r = (int)sqrt (p);
	int i = 1;
	while (6 * i - 1 <= r) {
		if (!p % 6 * i - 1)
			return false;
		if (!p % 6 * i + 1)
			return false;
		i++;
	}

	return true;
}

int main() {
	scanf ("%d", &p);
	
	if (Prim(p))
		printf ("Es primo");
	else
		printf ("No es primo");

    system ("pause > nul");
	return 0;
}
