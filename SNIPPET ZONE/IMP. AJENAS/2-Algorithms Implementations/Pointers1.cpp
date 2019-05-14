/*
Luis Enrique Bernal Fuentes
Algorithm: Pointers (Algo sobre Funciones y Punteros)
*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
    
double (*pf)(double);

int main(){
    
    pf = &sin;
    printf("%lf\n", (*pf)(3.141592654/2));
    pf = &cos;
    printf("%lf\n", (*pf)(3.141592654/2));

    system ("pause > nul");
    return 0;
}
    

