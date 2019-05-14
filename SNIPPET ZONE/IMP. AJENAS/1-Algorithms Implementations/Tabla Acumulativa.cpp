/*
Luis Enrique Bernal Fuentes
Algorithm: Tabla Acumulativa (Suma de una Matrix)
*/

#include <cstdio>
using namespace std;

int num, i, j, f, c, a[100][100];

int main() {
	freopen ("tabla.in", "r", stdin);
	freopen ("tabla.out", "w", stdout);
	
	scanf ("%d %d", &f, &c);
	for (i = 1; i <=f; i++)
		for (j = 1; j <= c; j++) {
			scanf ("%d", &num);
			a[i][j] = num + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
		
	for (i = 1; i <=f; i++) {
		for (j = 1; j <= c; j++)
			printf ("%d ", a[i][j]);
		printf ("\n");
	}
	
    return 0;
}
