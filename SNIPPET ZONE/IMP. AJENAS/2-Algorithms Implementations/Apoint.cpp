/*
Luis Enrique Bernal Fuentes
Algorithm: Apoint (Articulation Point) 
(Sirve para hallar los puntos de articulación de un grafo)
input 
5 5
1 2
1 3
3 4
2 4
4 5

output
1
4

*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int i, n, c, x, y, k, Td[100], low[100];
bool Dp[100];
vector <int> a[100];

void Apoint (int nod) {
	Td[nod] = low[nod] = ++k;
	for (int i = 0; i < a[nod].size(); i++) {
		int newn = a[nod][i];
		if (!low[newn]) {
			Apoint(newn);
			low[nod] <?= low[newn];
			if (Td[nod] <= low[newn])
				Dp[nod] = true;
		}
		else
			low[nod] <?= Td[newn];
	}
}

int main() {
	freopen ("apoint.in", "r", stdin);
	freopen ("apoint.out", "w", stdout);
	
	scanf ("%d %d", &n, &c);
	for (i = 1; i <= c; i++) {
		scanf ("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	Apoint(1);
	
	for (i = 1; i <= n; i++)
		if (Dp[i])
			printf ("%d\n", i);

	return 0;
}
