/*
Luis Enrique Bernal Fuentes
Algorithm: Depth First Search (Grapho)
Description: Sirve para encontrar el camino mínimo en un grafo
*/

#include <cstdio>
#include <vector>

#define oo 1 << 30
#define RANG 100
using namespace std;

typedef pair <int, int> two;
vector <two> A[RANG];
int v, a, nod, newn, cost, C[RANG];

void DFS (int nod) {
    for (int i = 0; i < A[nod].size(); i++) {
        newn = A[nod][i].first;
        cost = A[nod][i].second + C[nod];
        if (C[newn] > cost) {
            C[newn] = cost;
            DFS (newn);
        }
    }
}

int main() {
    freopen ("dfs.in", "r", stdin);
    freopen ("dfs.out", "w", stdout);
    
    scanf ("%d %d", &v, &a);
    for (int i = 0; i < a; i++) {
        scanf ("%d %d %d", &nod, &newn, &cost);
        A[nod].push_back (two (newn, cost));
        A[newn].push_back (two (nod, cost));
    }
    
    fill (C + 2, C + v + 1, oo);
    DFS (1);
    
    printf ("%d\n", C[v]);
    
    return 0;
}
