#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 10000;
int n, m, mark[MAX];
vector <int> G[MAX];
stack <int> S;

void dfs(int nod) {
    mark[nod] = 1;

    for(int i = 0; i < G[nod].size(); i++) {
        int newn = G[nod][i];

        if(!mark[newn])
            dfs(newn);
    }

    S.push(nod);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
        if(!mark[i]) dfs(i);

    while(!S.empty()) {
        printf("%d\n", S.top());
        S.pop();
    }

    return 0;
}
