/*
Luis Enrique Bernal Fuentes
Algorithm: Acumulative Table 
Description: Suma de una Matrix
*/

#include <cstdio>

#define RANG 100
using namespace std;

int f, c, T[RANG][RANG];

int main() {
	freopen ("tabla.in", "r", stdin);
	freopen ("tabla.out", "w", stdout);
	
	scanf ("%d %d", &f, &c);
	for (int i = 1; i <= f; i++)
		for (int j = 1; j <= c; j++) {
			scanf ("%d", &T[i][j]);
			T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
		}
	
	for (int i = 1; i <= f; i++) {
		for (int j = 1; j < c; j++)
			printf ("%d ", T[i][j]);
		printf ("%d\n", T[i][c]);
	}
	
	return 0;
}
