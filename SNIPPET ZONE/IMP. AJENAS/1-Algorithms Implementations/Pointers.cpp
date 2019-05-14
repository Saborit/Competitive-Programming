/*
Luis Enrique Bernal Fuentes
Algoithm: Pointers (Algunas cosas sobre punteros)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int mat[2][2], a[3], sum, *p;

int main() {
	
	for (int i = 0 ; i < 2; i++)
        for (int j = 0; j < 2; j++)
		  scanf ("%d", &mat[i][j]);
    printf ("%d\n", *(*(mat + 1) + 1));
	
    for (p = a; p < &a[3]; p++) {
        scanf ("%d", p);
        sum += *p;
    }
    
    printf ("%d\n", sum);


	system ("pause > nul");
	
	return 0;
}
