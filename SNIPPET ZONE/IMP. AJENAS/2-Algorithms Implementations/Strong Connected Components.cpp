/*
Luis Enrique Bernal Fuentes
Algorithm: Strong Connected Components
Description: Halla los Ciclos en un Grafo Dirigido
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 100
using namespace std;

vector <int> A[RANG];
stack <int> S;
int n, a, k, nod, newn, Low[RANG], Td[RANG];
bool M[RANG];

void stcomp (int nod) {
    Td[nod] = Low[nod] = ++k;
    S.push (nod);
    for (int i = 0; i < A[nod].size(); i++) {
        int newn = A[nod][i];
        if (!Low[newn]) {
            stcomp (newn);
            Low[nod] <?= Low[newn];
        }
        else
            if (!M[newn])
                Low[nod] <?= Td[newn];
    }

    if (Low[nod] == Td[nod]) {
        M[nod] = true;
        for (int j = 0; j != nod; S.pop()) {
            j = S.top();
			printf ("%d ", j);
		}
		
        printf ("\n");
    }
}

int main() {
    freopen ("stcomp.in", "r", stdin);
    freopen ("stcomp.out", "w", stdout);

    scanf ("%d %d", &n, &a);
    for (int i = 1; i <= a; i++) {
        scanf ("%d %d", &nod, &newn);
        A[nod].push_back (newn);
    }
    
	for (int i = 1; i <= n; i++)
		if (!Low[i])
			stcomp (i);

    return 0;
}


