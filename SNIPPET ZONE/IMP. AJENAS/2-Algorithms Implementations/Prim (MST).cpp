/*
Luis Enrique Bernal Fuentes
Algorithm: Prim 
Description: Sirve para encontrar el camino mínimo que une a todos los nodos
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define RANG 100
using namespace std;

typedef pair <int, int> two;
vector <two> A[RANG];
priority_queue <two, vector <two>, greater <two> > Q; 
bool M[RANG];
int n, a, newn, cost, nod, sol;

int main() {
	freopen ("prim.in", "r", stdin);
	freopen ("prim.out", "w", stdout);
	
	scanf ("%d %d", &n, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back(two (newn, cost));
		A[newn].push_back(two (nod, cost));
	}
	
	Q.push(two (0, 1));
	while (!Q.empty()) {
		nod = Q.top().second;
		cost = Q.top().first;
		Q.pop();
		if (!M[nod]) {
			M[nod] = true;
			sol += cost;
			for (int i = 0; i < A[nod].size(); i++) {
				newn = A[nod][i].first;
				if (!M[newn]) {
					cost = A[nod][i].second;
					Q.push(two (cost, newn));
				}
			}
		}
	}
	
	printf ("%d\n", sol);
	
	return 0;
} 
