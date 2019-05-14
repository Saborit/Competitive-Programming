/*
Luis Enrique Bernal Fuentes
Algorithm: Longest Increasing or Deacreasing Subsequence
Description: Sirve para coger la mayor cantidad de objetos. Como un Catcher pero más rápido
		   (<) --> lower_bound
                   (<=) --> upper_bound
*/
 
#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int n, m, up, N[RANG], Sol[RANG], Id[RANG], Last[RANG];

void write (int ID) {
	if (ID) {
		write (Last[ID]);
		printf ("%d ", N[ID]);
	}
}

int main() {
	freopen ("lis.in", "r", stdin);
	freopen ("lis.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &N[i]);
		
	for (int i = 1; i <= n; i++) {
		if (Sol[m] <= N[i]) {
			Sol[++m] = N[i];
			Id[m] = i;
			Last[i] = Id[m - 1]; 
		}	
		else {
			up = upper_bound (Sol + 1, Sol + m + 1, N[i]) - Sol;
			Sol[up] = N[i];
			Id[up] = i;
			Last[i] = Id[up - 1];
		}	
	}

	printf ("%d\n", m);
	write (Id[m]);
		
	return 0;
}


