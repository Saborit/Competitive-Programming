/*
Luis Enrique Bernal Fuentes
Algorithmo: Dijkstra
(Sirve para encontrar el camino mínimo en un grafo)
*/

#include <cstdio>
#include <vector>
#include <queue>
#define maxint 1 << 30
using namespace std;

typedef pair <int, int> par;
vector <par> a[100];
priority_queue <par, vector <par>, greater <par> > col;
int n, m, i, x, y, z, nextc, nextn, nod, cost[100];

int main() {
    freopen ("bfsford.in", "r", stdin);
    freopen ("bfsford.out", "w", stdout);
   
    scanf ("%d %d", &n, &m);
    for (i= 1; i <= m; i++) {
        scanf ("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
	
	//Dijkstra
	fill (cost + 2, cost + n + 1, maxint);
	for (col.push(make_pair(0, 1)); !col.empty(); col.pop()) {
		nod = col.top().second;
		for (i = 0; i < a[nod].size(); i++) {
			nextc = a[nod][i].second + cost[nod];
			nextn = a[nod][i].first;
			if (cost[nextn] > nextc) {
				cost[nextn] = nextc;
				col.push(make_pair(cost[nextn], nextn));
			}
		}
	}
	
	for (i = 1; i <= n; i++)
        printf ("%d ", cost[i]);
	
	return 0;
}
