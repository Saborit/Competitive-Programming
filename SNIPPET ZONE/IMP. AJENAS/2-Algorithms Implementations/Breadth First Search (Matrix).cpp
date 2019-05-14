/*
Luis Enrique Bernal Fuentes
Algorithm: Breadth First Search
Description: Sirve para encontrar el camino mínimo en una matrix
*/

#include <cstdio>
#include <queue>

#define oo 1 << 30
#define RANG 100
using namespace std;

const int
	mf[4] = {1, -1, 0, 0},
	mc[4] = {0, 0, 1, -1};
int x, y, f, c, nf, nc, cost, C[RANG][RANG];
char G[RANG][RANG];
typedef pair <int, int> two;
queue <two> Q;

int main() {
	freopen ("bfs.in", "r", stdin);
	freopen ("bfs.out", "w", stdout);
	
	scanf ("%d %d\n", &y, &x);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			scanf ("%c", &G[i][j]);
			C[i][j] = oo;
		}
		scanf ("\n");
	}

	for (Q.push (two (1, 1)), C[1][1] = 0; !Q.empty(); Q.pop()) {
		f = Q.front().first;
		c = Q.front().second;
		cost = C[f][c] + 1;
		for (int i = 0; i < 4; i++) {
			nf = f + mf[i];
			nc = c + mc[i];
			if (G[nf][nc] == '.' && C[nf][nc] > cost) {
				C[nf][nc] = cost;
				Q.push (two (nf, nc));
			}
		}
	}
	
	printf ("%d\n", C[y][x]);
	
	return 0;
}
