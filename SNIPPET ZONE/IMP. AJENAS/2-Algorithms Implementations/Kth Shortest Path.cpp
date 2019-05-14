/*
Luis Enrique Bernal Fuentes
Algorithm: Kth Shortest Path
Description: Halla todos los caminos con lo que se puede llegar a un nodo tanto en un grafo unidireccional como bidireccional.
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define RANG 100
using namespace std;

int n, a, start, end, k, nod, newn, newc, cost, V[RANG];
typedef pair <int, int> two;
vector <two> A[RANG];
priority_queue <two, vector <two>, greater <two> > Q;  

int main() {
	freopen ("ksp.in", "r", stdin);
	freopen ("ksp.out", "w", stdout);
	
	scanf ("%d %d %d %d %d", &n, &a, &start, &end, &k);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back(two (newn, cost));
		A[newn].push_back(two (nod, cost));
	}
	
	Q.push(two (0, start));
	while (!Q.empty()) {
		nod = Q.top().second;
		cost = Q.top().first;
		Q.pop();
		V[nod]++;
		
		if (nod == end) {
			printf ("%d\n", cost);
			if (V[nod] == k)
			   return 0;
		}
		for (int i = 0; i < A[nod].size(); i++) {
			newn = A[nod][i].first;
			if (V[newn] < k) {
				newc = A[nod][i].second + cost;
				Q.push(two (newc, newn));
			}
		}
	}
	
	for (int i = V[end]; i <= k; i++)
		printf ("-1\n");
	
	return 0;
}
