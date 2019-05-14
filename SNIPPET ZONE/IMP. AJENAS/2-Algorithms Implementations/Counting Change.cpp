/*
Luis Enrique Bernal Fuentes
Algorithm: Counting Change
Description: Sirve para ver de cuantas combinaciones se puede formar un número
		   con un determinado conjunto de números.
*/

#include <cstdio>

#define RANG 100
using namespace std;

int cn, num, N[RANG], D[RANG];

int main () {
    freopen ("counting_change.in", "r", stdin);
    freopen ("counting_change.out", "w", stdout);
    
    scanf ("%d %d", &cn, &num);
	for (int i = 0; i < cn; i++)
		scanf ("%d", &N[i]);

    D[0] = 1;
    for (int i = 0; i < cn; i++)
        for (int j = N[i]; j <= num; j++)
            D[j] += D[j - N[i]];

    printf ("%d\n", D[num]);
    
    return 0;
}
