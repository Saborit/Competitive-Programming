/*
Luis Enrique Bernal Fuentes
Algorithm: BFS-Lee (Breath First Search)
(Sirve para encontrar el camino mínimo en una matríz)
*/

#include <cstdio>
#include <queue>
#define oo 1 << 30
using namespace std;

const int
	mf[4] = {1, -1, 0, 0},
	mc[4] = {0, 0, 1, -1};
typedef pair <int, int> par;
queue <par> Q;
char a[100][100];
int i, j, x, y, f, c, nf, nc, newc, C[100][100];


int main() {
	freopen ("bfslee.in", "r", stdin);
	freopen ("bfslee.out", "w", stdout);
	
	scanf ("%d %d\n", &x, &y);
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= y; j++) {
			scanf ("%c", &a[i][j]);
			C[i][j] = oo;
		}
		scanf ("\n");
	}
	
	C[1][1] = 0;
	for (Q.push(par(1, 1)); !Q.empty(); Q.pop()) {
		f = Q.front().first;
		c = Q.front().second;
		newc = C[f][c] + 1;
		for (i = 0; i < 4; i++) {
			nf = f + mf[i];
			nc = c + mc[i];
			if (a[nf][nc] == '.' && C[nf][nc] > newc) {
				C[nf][nc] = newc;
				Q.push(par(nf, nc));
			}
		}
	}
	
	printf ("%d\n", C[x][y]);
	
	return 0;
}
