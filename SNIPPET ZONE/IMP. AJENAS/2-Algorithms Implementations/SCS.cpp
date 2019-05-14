/*
Luis Enrique Bernal Fuentes
Algorithm: SCC (Strong Connected Components)
*/

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector <int> a[100];
stack <int> S;
int i, x, n, c, y, low[100], Td[100], k; 

void stcomp (int nod) {
    Td[nod] = low[nod] = ++k;
    S.push(nod);
    for (int i = 0; i < a[nod].size(); i++) {
        int newn = a[nod][i];
        if (!low[newn]) {
            stcomp(newn);
            low[nod] <?= low[newn];
        }
        else
            low[nod] <?= Td[newn];
    }

    if (low[nod] == Td[nod]) {
        for (;;){
            int s = S.top();
            S.pop();
            printf ("%d ", s);
            if (s == nod)
                break;    
        } 
        printf ("\n");
    }
}

int main() {
    freopen ("stcomp.in", "r", stdin);
    freopen ("stcomp.out", "w", stdout);

    scanf ("%d %d", &n, &c);
    for (i = 1; i <= c; i++) {
        scanf ("%d %d", &x, &y);
        a[x].push_back(y);
    }
    
    stcomp(1);

    return 0;
}


