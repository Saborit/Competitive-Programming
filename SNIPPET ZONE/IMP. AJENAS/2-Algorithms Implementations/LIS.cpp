/*
Luis Enrique Bernal Fuentes
Algorithm: LIS
(Sirve para coger la mayor cantidad de objetos (Como un Catcher pero 
más rápido))
*/
 
#include <cstdio>
#include <algorithm>
using namespace std;

int i, n, m, up, a[100], id[100], last[100], nex[100];

void print(int m) {
	if (m) {
		print(last[--m]);
        printf ("%d ", a[last[m] + 1]);
    }
}

int main() {
	freopen ("lis.in", "r", stdin);
	freopen ("lis.out", "w", stdout);
	
	scanf ("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		
        if (a[i] >= nex[m]) {
            nex[++m] = a[i];	
			id[i] = i;
            last[m] = id[m - 1];
		}
		else {
			up = upper_bound (nex + 1, nex + m + 1, a[i]) - nex;
			nex[up] = a[i];
			id[up] = i;
            last[up] = id[up - 1];
		}	
	}
	
	print(m);
	
	return 0;
}
