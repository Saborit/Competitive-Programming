/*
Luis Enrique Bernal Fuentes
Algorithm: Binary Search
Description: Sirve para encontrar un número determinado en un arreglo
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int cn, sn, pos, N[RANG];

int Binary_Search (int start, int end, int num) {
	int piv = end;
	
	while (N[piv] != num && start <= end) {
		piv = start + (end - start) / 2;
		if (N[piv] > num)
			end = piv - 1;
		else
			start = piv + 1;
	}

	if (N[piv] == num)
		return piv;
	else
		return 0;
}

int main () {
    freopen ("binary_search.in", "r", stdin);
    freopen ("binary_search.out", "w", stdout);

	scanf ("%d %d", &cn, &sn);
	for (int i = 1; i <= cn; i++)
		scanf ("%d", &N[i]);
	
	pos = Binary_Search (1, cn, sn);
	if (pos)
		printf ("Posición--> %d\n", pos);
	else
		printf ("No está\n");
	
	return 0;
}

 
