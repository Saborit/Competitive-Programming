/*
Luis Enrique Bernal Fuentes
Algoritmo: KMP (Knuth Morris Pratt) 
(Sirve para hallar las veces que se repite una secuencia dada en un texto)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, ts, tt, ini, fail[100];
char s[100], t[100];

int main() {
    freopen ("kmp.in", "r", stdin);
    freopen ("kmp.out", "w", stdout);

    scanf ("%s", &s);
    scanf ("%s", &t);

    ts = strlen(s);
    tt = strlen(t);


    /*for (i = 1; i < ts; i++){
        ini = fail[i];
        if (s[i] == s[ini])
            fail[i + 1] = ini + 1;
    }*/
    //Pre KMP
    for (i = 1; i < ts; i++) {
        fail[i] = fail[ini];
        if (s[i] == s[ini])
            ini++;
        else
            fail[i] = ini;
    }
    
    i = 0;
    //KMP
    /*while (j < tt){
        while (s[i] == t[j] && j < tt) {
			i++; 
			j++;
		}
        if (i == 0) {
			j++; 
			continue;
		}
        if (i > ts - 1) {
            printf ("%d ", j - ts + 1);
            i = ini;
        }
        else i = fail[i];
    }*/

    for (i = 0; i < ts; i++)
        printf ("%d ", fail[i]);
    
    return 0;
}
