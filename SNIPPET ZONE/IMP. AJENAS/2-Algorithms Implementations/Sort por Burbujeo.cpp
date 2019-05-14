/*
Luis Enrique Bernal Fuentes
Algorithm: Sort por Burbujeo (Sirve para organizar números y caracteres)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, cant;
int a[100];

int main() {
	freopen ("qcksort.in", "r", stdin);
    freopen ("qcksort.out", "w", stdout);
	
	scanf ("%d", &cant);
    for (i = 1; i <= cant; i++)
        scanf ("%d", &a[i]);
	
	for (i = 1; i < cant; i++)
		for (j = i + 1; j <= cant; j++)
			if (a[i] > a[j]) swap(a[i], a[j]);
	
	for (i = 1; i <= cant; i++)
        printf ("%d ", a[i]);
	
	return 0;
}
