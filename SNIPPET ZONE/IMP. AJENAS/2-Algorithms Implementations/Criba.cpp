/*
Luis Enrique Bernal Fuentes
Algorithm: Criba (Halla todos los números primos)
*/

#include <cstdio>
#include <cmath>
using namespace std;

int i, fin, num, j;
bool Dp[4000000];

void Criba() {
	for (i = 2; i <= fin ; i++)
		if (Dp[i] == false) {
			for (j = i + i; j <= num; j += i)
				Dp[j] = true; 
		}
}

int main () {
	freopen ("criba.in", "r", stdin);
	freopen ("criba.out", "w", stdout);
	
	scanf ("%d", &num);
	
    fin = int (sqrt(num));
    Criba();
	
	for (i = 2; i <= num; i++)
		if (Dp[i] == false) printf ("%d ", i);
	
	return 0;
}
