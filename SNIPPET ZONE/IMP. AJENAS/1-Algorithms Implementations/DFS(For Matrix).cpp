/*
Luis Enrique Bernal Fuentes
Algorithm: DFS
(Sirve para encontrar el camino mínimo en una Matrix)
*/

#include <cstdio>
#include <algorithm>
#define maxint 1 << 30
using namespace std;

const int
    mf[4] = {-1, 1, 0, 0},
    mc[4] = {0, 0, -1, 1};
	
typedef pair <char, int> par;
par a[100][100];
int i, j, f, c, nf, nc, cost;

//DFS(Para una matrix)
void DFS (int f, int c) {
    for (int i = 0; i < 4; i++) {
        nf = f + mf[i];
        nc = c + mc[i];
        cost = a[f][c].second + 1;
        if (a[nf][nc].first == '.' && a[nf][nc].second > cost) {
            a[nf][nc].second = cost;
            DFS(nf,nc);
        }
    }
}

int main() {
    freopen ("dfs.in", "r", stdin);
    freopen ("dfs.out", "w", stdout);
    
    for (i = 1; i <= 4; i++){
        for (j = 1; j <= 4; j++){
            scanf ("%c", &a[i][j].first);
            a[i][j].second = maxint;
        }
        scanf ("%c", &a[0][0].first);
    }

    a[1][1].second = 0;
    DFS(1,1);
    
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++)
            if (a[i][j].first == '*')
                printf ("%s", "# ");
            else
                printf ("%d ", a[i][j].second);
        printf ("%\n");
    }

return 0;
}
