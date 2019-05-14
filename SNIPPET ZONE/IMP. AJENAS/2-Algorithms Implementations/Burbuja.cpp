/* 
Luis Enrique Bernal Fuentes
Algorithm: Burbuja (Para ordenar números y caracteres)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int cant, i, j, inter;
int a[100];
 
int main() {
    freopen( "burbuja.in", "r", stdin );
    freopen( "burbuja.out", "w", stdout );

    scanf( "%d", &cant );//leer
    for ( i = 1; i <= cant; i++ )
        scanf ("%d", &a[i]);
    
    //Burbuja
    j = cant;
    for ( i = 1; i < j; i++) {
        if (a[i] > a[i+1])
            swap (a[i], a[i + 1]);  
        if (j-1 == i) {
            i = 1;
            j--;
        }
    }

    for (i = 1; i <= cant; i++)//Imprimir
        printf("%d ", a[i]);

    return 0;
} 
