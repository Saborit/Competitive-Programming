/*
Luis Enrique Bernal Fuentes
Algorithm: Kruskal (MST) with Disjoin Set
Descriptions: Sirve para encontrar el camino mínimo que une a todos los nodos
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int n, a, nod, newn, cost, setnod, setnewn, sol, Set[RANG], Rank[RANG];
struct tri {
int nod, newn, cost;

	tri (int a = 0, int b = 0, int c = 0) {
		nod = a;
		newn = b;
		cost = c;
	}
	
	bool operator < (const tri &p) const {
		if (cost != p.cost)
			return cost < p.cost;
		if (nod != p.nod)
			return nod < p.nod;
		return newn < p.newn;
	}
	
} A[RANG];

void make_set (int i) {
	Set[i] = i;
	Rank[i] = 1;
}

int find_set (int nod) {
	if (Set[nod] != nod)
		Set[nod] = find_set (Set[nod]);
	return Set[nod];
}

void join_set (int nod, int newn) {
	if (Rank[nod] > Rank[newn]) {
		Set[newn] = nod;
		Rank[nod]++;
	}
	else {
		Set[nod] = newn;
		Rank[newn]++;
	}
}

int main() {
	freopen ("kruskal.in", "r", stdin);
	freopen ("kruskal.out", "w", stdout);
	
	scanf ("%d %d", &n, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[i] = tri (nod, newn, cost); 
	}
	
	sort (A, A + a);
	for (int i = 1; i <= n; i++)
		make_set (i);
	
	for (int i = 0; i < a; i++) {
		setnod = find_set (A[i].nod);
		setnewn = find_set (A[i].newn);
		if (setnod != setnewn) {
			sol += A[i].cost;
			join_set (setnod, setnewn);
		}
	}
	
	printf ("%d\n", sol);
	
	return 0;
}
