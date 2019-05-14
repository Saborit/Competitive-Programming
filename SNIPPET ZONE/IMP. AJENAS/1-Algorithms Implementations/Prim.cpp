/*
Luis Enrique Bernal Fuentes
Algorithm:MST Prim 
(Sirve para encontrar el camino mínimo que une a todos los nodos)
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> par;
vector <par> a[100];
priority_queue <par, vector <par>, greater <par> > Q; 
bool Dp[100];
int i, x, y, z, n, c, newn, newc, nod, sol;

int main() {
	freopen ("prim.in", "r", stdin);
	freopen ("prim.out", "w", stdout);
	
	scanf ("%d %d", &n, &c);
	for (i = 1; i <= c; i++) {
		scanf ("%d %d %d", &x, &y, &z);
		a[x].push_back(par(y, z));
		a[y].push_back(par(x, z));
	}
	
	for (Q.push(par(0, 1)); !Q.empty(); Q.pop()) {
		nod = Q.top().second;
		newc = Q.top().first;
		if (!Dp[nod]) {
			Dp[nod] = true;
			sol += newc;
			for (i = 0; i < a[nod].size(); i++) {
				newn = a[nod][i].first;
				if (!Dp[newn]) {
					newc = a[nod][i].second;
					Q.push(par(newc, newn));
				}
			}
		}
	}
	
	printf ("%d\n", sol);
	
	return 0;
} 
