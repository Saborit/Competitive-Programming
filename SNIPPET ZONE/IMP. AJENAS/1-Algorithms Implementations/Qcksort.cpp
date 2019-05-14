/*
Luis Enrique Bernal Fuentes
Algorithm: Qcksort (Sirve para organizar números y caracteres)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int cant, i;
int a[100];

//Qcksort
void qcksort (int ini, int fin) {
    int f, inter, piv;
    i = ini; f = fin;  piv = a[(i + f) / 2];
    do {
        while (a[i] < piv) i++;
        while (a[f] > piv) f--;
        if (i <= f) {
            swap(a[i], a[f]);
            i++; f--;
        }
    } while (i < f);
    if (f > ini) qcksort (ini, f);
    if (i < fin) qcksort (i, fin);
}

int main () {
    freopen ("qcksort.in", "r", stdin);
    freopen ("qcksort.out", "w", stdout);

    scanf ("%d", &cant);
    for (i = 0; i < cant; i++)
        scanf ("%d", &a[i]);

    qcksort (0, cant-1);

    for (i = 0; i < cant; i++)
        printf ("%d ", a[i]);
   
    
    return 0;
} 

