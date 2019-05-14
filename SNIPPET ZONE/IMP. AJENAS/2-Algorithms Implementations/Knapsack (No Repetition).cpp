/*
Luis Enrique Bernal Fuentes
Algorithm: Knapsack
Description: Sirve para escoger lo mejor ha hechar a la Mochila sin repetir objetos
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int n, m, T[RANG], V[RANG], C[RANG];
bool M[RANG];

int main () {
    freopen ("knapsack.in", "r", stdin);
    freopen ("knapsack.out", "w", stdout);

    scanf ("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &T[i], &V[i]);

    //Knapsack (No Repetiton)
	M[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= T[i]; j--)
			if (M[j - T[i]]) {
				M[j] = true;
				C[j] >?= C[j - T[i]] + V[i];
			}
            
    printf ("%d", C[m]);
    
    return 0;
}
