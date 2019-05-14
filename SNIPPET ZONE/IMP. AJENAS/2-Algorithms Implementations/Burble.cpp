/* 
Luis Enrique Bernal Fuentes
Algorithm: Burble 
Description: Para ordenar números y caracteres
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int cn, cn1;
int N[RANG];
 
int main() {
    freopen( "burble.in", "r", stdin );
    freopen( "burble.out", "w", stdout );
	
	scanf ("%d", &cn);
	for (int i = 1; i <= cn; i++)
		scanf ("%d", &N[i]);
	
	cn1 = cn;
	for (int i = 1; i < cn; i++) {
		if (N[i] > N[i + 1])
			swap (N[i], N[i + 1]);
		if (i == cn - 1) {
			i = 0;
			cn--;
		}
	}
	
	for (int i = 1; i < cn1; i++)
		printf ("%d ", N[i]);
	printf ("%d\n", N[cn1]);

    return 0;
}
