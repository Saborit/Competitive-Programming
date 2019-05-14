/*
Luis Enrique Bernal Fuentes
Algorithm: Articulation Points 
Description: Sirve para hallar los puntos de articulación de un grafo
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 100	
using namespace std;

int v, a, nod, newn, k, Td[RANG], Low[RANG];
vector <int> A[RANG];
stack <int> Q;

void AP (int nod) {
	Td[nod] = Low[nod] = ++k;
	for (int i = 0; i < A[nod].size(); i++) {
		int newn = A[nod][i];
		if (!Low[newn]) {
			AP(newn);
			Low[nod] <?= Low[newn];
			if (Td[nod] <= Low[newn])
				Q.push (nod);
		}
		else
			Low[nod] <?= Td[newn];
	}
}

int main() {
	freopen ("ap.in", "r", stdin);
	freopen ("ap.out", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d", &nod, &newn);
		A[nod].push_back (newn);
		A[newn].push_back (nod);
	}
	
	AP (1);
	
	for (; !Q.empty(); Q.pop())
		printf ("%d\n", Q.top());

	return 0;
}
