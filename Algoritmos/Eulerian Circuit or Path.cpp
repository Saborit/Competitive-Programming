#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

int n, a, deg[100], ni = 1, k;
vector <int> G[100];
stack <int> sol;

struct edge {
    int ni, nf, mark;

    edge() {}

    edge(int a, int b) {
        ni = a, nf = b, mark = 0;
    }

    int nod(int a) {
        return a == ni ? nf : ni;
    }
} A[100];

void dfs(int nod) {
    for(int i = 0; i < G[nod].size(); i++) {
        int id = G[nod][i];

        if(!A[id].mark) {
            A[id].mark = 1;
            dfs(A[id].nod(nod));
        }
    }

    sol.push(nod);
}

int main() {
    freopen("euler.in", "r", stdin);
    freopen("euler.out", "w", stdout);

    cin >> n >> a;
    for(int i = 1; i <= a; i++) {
        int a, b; cin >> a >> b;

        A[i] = edge(a, b);
        G[a].push_back(i);
        G[b].push_back(i);

        deg[a]++, deg[b]++;
    }

    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2) {
            k++, ni = i;

            if(k > 2) {
                cout << "No es Euleriano\n";
                return 0;
            }
        }
    }

    dfs(ni);

    if(!k) cout << "Circuito Euleriano\n";
    else cout << "Camino Euleriano\n";

    while(!sol.empty()) {
        cout << sol.top() << endl;
        sol.pop();
    }

    return 0;
}
