#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 100;
int n, m, L[MAX], P[MAX][MAX], Log, q;
vector <int> G[MAX];

void dfs(int nod, int l) {
    L[nod] = l;
    Log = log2(l);

    for(int i = 1; i <= Log; i++)
        P[nod][i] = P[P[nod][i - 1]][i - 1];

    for(int i = 0; i < G[nod].size(); i++) {
        int newn = G[nod][i];
        dfs(newn, l + 1);
    }
}

int lca(int a, int b) {
    if(L[a] < L[b])
        swap(a, b);

    Log = log2(L[a]);
    for(int i = Log; i >= 0; i--)
        if(L[a] - (1 << i) >= L[b])
            a = P[a][i];

    if(a == b) return a;

    Log = log2(L[a]);
    for(int i = Log; i >= 0; i--)
        if(P[a][i] != P[b][i] && P[a][i])
            a = P[a][i], b = P[b][i];

    return P[a][0];
}

int main() {
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].push_back(b);

        if(a > b) swap(a, b);
        P[b][0] = a;
    }

    dfs(1, 1);

    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}
