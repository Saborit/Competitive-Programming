/*
Luis Enrique Bernal Fuentes
Algorithm: Mochila sin Repetición
(Sirve para escoger lo mejor ha hechar
a la Mochila repitiendo objetos)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int N, cant, i, j;
int tam[10000], val[10000], cos[10000];
bool Dp[10000];

int main () {
    freopen ("mochila.in", "r", stdin);
    freopen ("mochila.out", "w", stdout);

    scanf ("%d %d", &N, &cant);
    for (i = 1; i <= cant; i++)
        scanf ("%d %d", &tam[i], &val[i]);

    //Mochila con Repetición                                     
    Dp[0] = true;
    for (i = 1; i <= cant; i++)
        for (j = tam[i]; j <= N; j++)
            if (Dp[j - tam[i]]){
                Dp[j] = true;
                cos[j] >?= cos[j - tam[i]] + val[i];
            }

    printf ("%d", cos[N]);
    
    return 0;
}
