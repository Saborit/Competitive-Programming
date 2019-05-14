/*
Luis Enrique Bernal Fuentes
Algorithm: Rectangle Cut
Descriptions: Halla la menor cantidad de rectangulos que se pueden formar
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int f, c, l, A[RANG][RANG];

int main() {
	freopen ("rcut.in", "r", stdin);
	freopen ("rcut.out", "w", stdout);
	
	scanf ("%d %d", &f, &c);
	
	l = max (f, c);
	for (int i = 1; i <= l; i++) {
		A[1][i] = A[i][1] = i;
		A[i][i] = 1;
	}
		
	for (int i = 2; i <= l; i++)
		for (int j = i + 1; j <= l + 1; j++) {
			A[i][j] = i * j;
			for (int k = 1; k <= j / 2; k++)
				A[i][j] <?= A[i][k] + A[i][j - k];
			for (int k = 1; k <= i / 2; k++)
				A[i][j] <?= A[k][j] + A[i - k][j];
			A[j][i] = A[i][j];
		}
	
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++)
			printf ("%d ", A[i][j]);
		printf ("\n");
	}
	
	printf ("%d\n", A[f][c]);
	
	return 0;
}
