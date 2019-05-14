/*
Luis Enrique Bernal Fuentes
Algorithm: Contichager
(Sirve para ver de cuantas formas se puede formar un número)
*/

#include <cstdio>
using namespace std;

int i, j, ini, fin, num;
int cost[100];

int main () {
    freopen ("contichager.in", "r", stdin);
    freopen ("contichager.out", "w", stdout);
    
    scanf ("%d %d %d", &ini, &fin, &num);

    //Contichager
    cost[0] = 1;
    for (i = ini; i <= fin; i++)
        for (j = i; j <= num; j++)
            cost[j] += cost[j - i];

    printf ("%d", cost[num]);
    
    return 0;
}
