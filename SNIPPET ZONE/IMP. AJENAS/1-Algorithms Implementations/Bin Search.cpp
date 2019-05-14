/*
Luis Enrique Bernal Fuentes
Algorithm: Bin Search
(Sirve para encontrar un número determinado en un arreglo)
*/

#include <cstdio>
using namespace std;

int i, ini, fin, piv, cant, comp;
int list[100];

int main () {
    freopen ("bins.in", "r", stdin);
    freopen ("bins.out", "w", stdout);
    
    scanf ("%d %d", &cant, &comp);
    for (i = 1; i <= cant; i++)
        scanf ("%d", &list[i]);

    
    //Busqueda Binaria
    piv = cant; 
    fin = cant;
    ini = 1;
    while ((list[piv] != comp) && (piv - ini > 1)){
        if (list[piv] < comp) {
            ini = piv;
            piv = fin - piv;
        }
        else {
            fin = piv;
            piv = piv - ini;
        }
        piv = ini + ((piv + 1) / 2);
    }

    if (list[piv] == comp)
        printf ("%d %d si está",comp, piv);
    else
        printf ("%d no está",comp);

    return 0;
}
