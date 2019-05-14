/*
Luis Enrique Bernal Fuentes
Algorithm: BFS-Ford
(Sirve para encontrar el camino mínimo en un grafo)
*/

#include <cstdio>
#include <vector>
#include <queue>
#define oo 1 << 30
using namespace std;

typedef pair <int, int> par;
vector <par> a[100];
queue <int> Q;
int i, n, c, x, y, z, nod, newn, newc, C[100];

int main() {
	freopen ("bfsford.in", "r", stdin);
	freopen ("bfsford.out", "w", stdout);
	
	scanf ("%d %d", &n, &c);
	for (i = 1; i <= c; i++) {
		scanf ("%d %d %d", &x, &y, &z);
		a[x].push_back(par(y, z));
		a[y].push_back(par(x, z));
	}
	
	fill (C + 2, C + n + 1, oo);
	for (Q.push(1); !Q.empty(); Q.pop()) {
		nod = Q.front();
		for (i = 0; i < a[nod].size(); i++) {
			newn = a[nod][i].first;
			newc = a[nod][i].second + C[nod];
			if (C[newn] > newc) {
				C[newn] = newc;
				Q.push(newn);
			}
		}
	}
	
	for (i = 1; i <= n; i++)
		printf ("%d ", C[i]);
	
	return 0;
}
