/*
Luis Enrique Bernal Fuentes
Algorithm: Depth First Search (Matrix)
Description: Sirve para encontrar el camino mínimo en una Matrix
*/

#include <cstdio>

#define oo 1 << 30
#define RANG 100
using namespace std;

const int
    mf[4] = {-1, 1, 0, 0},
    mc[4] = {0, 0, -1, 1};
	
int y, x, nf, nc, C[RANG][RANG];
char G[RANG][RANG];

void DFS (int f, int c) {
    int cost = C[f][c] + 1;
    for (int i = 0; i < 4; i++) {
        nf = f + mf[i];
        nc = c + mc[i];
        if (G[nf][nc] == '.' && C[nf][nc] > cost) {
            C[nf][nc] = cost;
            DFS (nf, nc);
        }
    }
}

int main() {
    freopen ("dfs.in", "r", stdin);
    freopen ("dfs.out", "w", stdout);
    
    scanf ("%d %d\n", &y, &x);
    
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            scanf ("%c", &G[i][j]);
            C[i][j] = oo;
        }
        scanf ("\n");
    }

    C[1][1] = 0;
    DFS (1, 1);
    
    printf ("%d\n", C[y][x]);

    return 0;
}
