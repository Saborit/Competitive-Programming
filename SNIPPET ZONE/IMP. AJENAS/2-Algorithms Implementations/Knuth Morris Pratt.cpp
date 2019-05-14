/*
Luis Enrique Bernal Fuentes
Algoritmo: Knuth Morris Pratt 
Description: Sirve para hallar las veces que se repite una secuencia dada en un texto
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int i, j, lS, lT, m, F[RANG];
char S[RANG], T[RANG];

int main() {
    freopen ("kmp.in", "r", stdin);
    freopen ("kmp.out", "w", stdout);

    scanf ("%s", &S);
    scanf ("%s", &T);

    lS = strlen(S);
    lT = strlen(T);

	//Pre KMP
    for (i = 1; i < lS; i++) {
        if (S[m] != S[i])
            m = 0;
		if (S[m] == S[i])
			m++;
		F[i] = m;
    }
    
	//KMP
	i = 0;
	while (i < lT) {
		if (T[i++] == S[j])
			j++;
		else
            if (j) {
			    j = F[j - 1];
                i--;
            }
		if (j == lS) {
			printf ("%d ", i - j + 1);
			j = F[j - 1];
		}
	}
	    
    return 0;
}
