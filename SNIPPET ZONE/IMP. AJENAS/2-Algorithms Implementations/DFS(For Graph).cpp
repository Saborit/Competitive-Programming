/*
Luis Enrique Bernal Fuentes
Algorithm: DFS
(Sirve para encontrar el camino mínimo en un grafo)
*/

#include <cstdio>
#include <vector>
#define maxint 1 << 30
using namespace std;

typedef pair <int, int> par;
vector <par> a[100];
int n, m, i, x, y, z, nextc, nextn, cost[100];

//DFS
void DFS (int nod) {
    for (int i = 0; i < a[nod].size(); i++) {
        nextc = a[nod][i].second;
        nextn = a[nod][i].first;
        if (cost[nextn] > nextc + cost[nod]){
            cost[nextn] = nextc + cost[nod];
            DFS(nextn);
        }
    }
}

int main() {
    freopen ("bfs.in", "r", stdin);
    freopen ("bfs.out", "w", stdout);
    
    scanf ("%d %d", &n, &m);
    for (i= 1; i <= m; i++) {
        scanf ("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    
    fill (cost + 2, cost + n + 1, maxint);
    DFS(1);
    
	for (i = 1; i <= n; i++)
        printf ("%d ", cost[i]);
    
    return 0;
}
