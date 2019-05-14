/*
Luis Enrique Bernal Fuentes
Algorithm: Floyd Warshall 
(Sirve para hallar la distancia mínima entre todos los nodos)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, x, y, k, n, c, a[100][100];

int main() {
    freopen ("floyd.in", "r", stdin);
    freopen ("floyd.out", "w", stdout);

    memset (a, 31, sizeof(a));
    scanf ("%d %d", &n, &c);
    for (i = 1; i <= c; i++) {
        scanf ("%d %d", &x, &y);
        scanf ("%d\n", &a[x][y]);
        a[i][i] = 0;
    }
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                a[i][j] <?= a[i][k] + a[k][j];

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] > 30)
                printf ("# ");
            else
                printf ("%d ", a[i][j]);
        printf ("\n");
    }

    return 0;
}
