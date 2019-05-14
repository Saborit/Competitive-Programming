/*
Luis Enrique Bernal Fuentes
Algorithm: Catcher
(Sirve para intersectar la mayor cantidad posible de objetos)
*/

#include <cstdio>
#include <algorithm>
using namespace std; 

int cost[100], alt[100];
int i, j, k, l, cant, com;
 
int main () {
    freopen ("catcher.in", "r", stdin);
    freopen ("catcher.out", "w", stdout);
  
    scanf ("%d", &cant);
    for (i = 1; i <= cant; i++)
        scanf ("%d", &alt[i]);

    //Catcher
    cost[cant] = 1;
    for (i = cant-1; i > 0; i--) {
        for (k = i + 1; k <= cant; k++)
            if (alt[i] > alt[k] && cost[i] < cost[k])
                cost[i] = cost[k];
        cost[i]++;
        com >?= cost[i];
    }
  
  printf ("%d", com);
  
  return 0;
}
