#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 101;
int n, m, dp[MAX][MAX];

int main() {
    freopen("cut.in", "r", stdin);
    freopen("cut.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= max(n, m); i++)
        dp[i][i] = 1;

    for(int i = 1; i <= n; i++)
        dp[i][1] = i;

    for(int i = 1; i <= m; i++)
        dp[1][i] = i;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j]) continue;

            int result = 1 << 28;

            for(int k = 1; k < j; k++)
                result = min(result, dp[i][k] + dp[i][j - k]);

            for(int k = 1; k < i; k++)
                result = min(result, dp[k][j] + dp[i - k][j]);

            dp[i][j] = result;
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}
