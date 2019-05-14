/*
Luis Enrique Bernal Fuentes
Algorithm: Bridges
Description: Funciona como un Articulation Point, pero en este caso con las aristas. 
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 100
using namespace std;

struct tri {
	int nod, newn;
	bool marc;
	
	tri (int a = 0, int b = 0) {
		nod = a;
		newn = b;
		marc = false;
	}
	
	int nextn (int a) {
		if (a == nod)
			return newn;
		return nod;
	}
} A[RANG];
typedef pair <int, int> two;
stack <two> Q;
vector <int> Id[RANG];
int nod, newn, v, a, k, Td[RANG], Low[RANG];

void Bridges (int nod) {
	Td[nod] = Low[nod] = ++k;
	for (int i = 0; i < Id[nod].size(); i++) {
		int I = Id[nod][i];
		int newn = A[I].nextn (nod);
		if (!Low[newn]) {
			A[I].marc = true;
			Bridges (newn);
			Low[nod] <?= Low[newn];
			if (Td[nod] < Low[newn])
				Q.push (two (nod, newn));
		}
		else
			if (!A[I].marc)
				Low[nod] <?= Td[newn];
	}
}

int main() {
	freopen ("bridges.in", "r", stdin);
	freopen ("bridges.out", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d", &nod, &newn);
		A[i] = tri (nod, newn);
		Id[nod].push_back (i);
		Id[newn].push_back (i);
	}
	
	Bridges (1);
	
	printf ("%d\n", Q.size());
	for (; !Q.empty(); Q.pop())
		printf ("%d -> %d\n", Q.top().first, Q.top().second);
	
	return 0;
}
