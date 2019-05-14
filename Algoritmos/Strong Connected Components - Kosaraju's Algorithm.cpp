#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 10000;
int n, m, mark[MAX], F[MAX], k;
vector <int> G[MAX], Gt[MAX];

void dfs_traverse(int nod) {
    mark[nod] = 1;

    for(int i = 0; i < G[nod].size(); i++) {
        int newn = G[nod][i];

        if(!mark[newn])
            dfs_traverse(newn);
    }

    F[k--] = nod;
}

void dfs_transposed(int nod) {
    mark[nod] = 1;
    printf("%d ", nod);

    for(int i = 0; i < Gt[nod].size(); i++) {
        int newn = Gt[nod][i];

        if(!mark[newn])
            dfs_transposed(newn);
    }
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &m); k = n;
    for(int i = 1; i <= m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        G[a].push_back(b);
        Gt[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        if(!mark[i])
            dfs_traverse(i);

    for(int i = 1; i <= n; i++)
        mark[i] = 0;

    for(int i = 1; i <= n; i++) {
        int nod = F[i];

        if(!mark[nod]) {
            dfs_transposed(nod);
            printf("\n");
        }
    }

    return 0;
}
