/*
Luis Enrique Bernal Fuentes
Algorithm: Floyd Warshall 
Description: Sirve para hallar la distancia mínima entre todos los nodos
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int v, a, nod, newn, A[RANG][RANG];

int main() {
    freopen ("floyd.in", "r", stdin);
    freopen ("floyd.out", "w", stdout);

    memset (A, 30, sizeof (A));
    scanf ("%d %d", &v, &a);
    for (int i = 1; i <= a; i++) {
        scanf ("%d %d", &nod, &newn);
        scanf ("%d\n", &A[nod][newn]);
        A[i][i] = 0;
    }
    
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            for (int k = 1; k <= v; k++)
                A[i][j] <?= A[i][k] + A[k][j];

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++)
            if (A[i][j] > 30)
                printf ("# ");
            else
                printf ("%d ", A[i][j]);
        printf ("\n");
    }

    return 0;
}
