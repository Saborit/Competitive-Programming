/*
Luis Enrique Bernal Fuentes
Algorithm: Eulerian Path/Circuit
Description: 
*/

#include <cstdio>
#include <queue>
#include <vector>

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

vector <int> Id[RANG];
queue <int> Q;
int v, a, nod, newn, impar, start = 1, Grade[RANG], Td[RANG], Low[RANG];

void Euler (int nod) {
	for (int i = 0; i < Id[nod].size(); i++) {
		int I = Id[nod][i];
		if (!A[I].marc) {
			A[I].marc = true;
			Euler (A[I].nextn (nod));
		}
	}
	Q.push (nod);
}

int main() {
    freopen ("euler.in", "r", stdin);
    freopen ("euler.out", "w", stdout);

	scanf ("%d %d", &v, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d", &nod, &newn);
		Id[nod].push_back (i);
		Id[newn].push_back (i);
		A[i] = tri (nod, newn);
		Grade[nod]++;
		Grade[newn]++;
	}
	
	for (int i = 1; i <= v; i++)
		if (Grade[i] % 2) {
			impar++;
			start = i;
			if (impar > 2) {
				printf ("The Graph is not Eurelian\n");
				return 0;
			}
		}
	
	Euler (start);
	
	if (!impar)
		printf ("Eulerian Circuit\n");
	else
		printf ("Eulerian Path\n");
	for (; !Q.empty(); Q.pop())
		printf ("%d ", Q.front());
	
	return 0;
}
