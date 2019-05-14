/*
Luis Enrique Bernal Fuentes
Algorithm: Breadth First Search
Description: Sirve para encontrar el camino mínimo en un grafo
*/

#include <cstdio>
#include <vector>
#include <queue>

#define oo 1 << 30
#define RANG 100
using namespace std;

int v, a, nod, newn, cost, C[RANG];
typedef pair <int, int> two;
vector <two> A[RANG];
queue <int> Q;

int main() {
	freopen ("bfs.in", "r", stdin);
	freopen ("bfs.out", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back (two (newn, cost));
		A[newn].push_back (two (nod, cost));
	}

	fill (C + 1, C + v + 1, oo);
	C[1] = 0;
	for (Q.push(1); !Q.empty(); Q.pop()) {
		nod = Q.front();
		for (int i = 0; i < A[nod].size(); i++) {
			newn = A[nod][i].first;
			cost = A[nod][i].second + C[nod];
			if (C[newn] > cost) {
				C[newn] = cost;
				Q.push (newn);
			}
		}
	}
	
	printf ("%d\n", C[v]);
	
	return 0;
}
