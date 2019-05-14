#include <cstdio>
#include <algorithm>
using namespace std;

const int
    MAX = 305,
    oo = 1e9;
int n, m, q, dp[MAX][MAX];

int main() {
    freopen("hurdles.in", "r", stdin);
    freopen("hurdles.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = oo;

    for(int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        dp[a][b] = c;
    }

    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));

    while(q--) {
        int a, b;
        scanf("%d%d", &a, &b);

        if(dp[a][b] == oo) {
            printf("-1\n");
            continue;
        }

        printf("%d\n", dp[a][b]);
    }

    return 0;
}
