#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 2e5 + 5;
char s[MAX], t[MAX];
int n, stp, I[MAX], P[20][MAX];

struct data {
    int a, b, p;

    bool operator < (const data &p) const {
        if(a != p.a)
            return a < p.a;
        return b < p.b;
    }
} T[MAX];

int lcp(int x, int y) {
    int ans = 0;

    for(int i = stp; i >= 0 && x <= n && y <= n; i--) {
        if(P[i][x] == P[i][y]) {
            int p = 1 << i;
            x += p, y += p, ans += p;
        }
    }

    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i++)
        P[0][i] = s[i] - 'a' + 1;

    stp = 1;
    for(int k = 1; k <= n; stp++, k *= 2) {
        for(int i = 1; i <= n; i++) {
            T[i].a = P[stp - 1][i];
            T[i].b = i + k > n ? -1 : P[stp - 1][i + k];
            T[i].p = i;
        }

        sort(T + 1, T + n + 1);

        P[stp][T[1].p] = 1;
        for(int i = 2; i <= n; i++) {
            if(T[i].a == T[i - 1].a && T[i].b == T[i - 1].b) {
                P[stp][T[i].p] = P[stp][T[i - 1].p];
                continue;
            }

            P[stp][T[i].p] = i;
        }
    }

    stp--;

    for(int i = 1; i <= n; i++)
        I[P[stp][i]] = i;

    int sol = 0;
    for(int i = 1; i <= n; i++)
        sol = max(sol, lcp(I[i], I[i - 1]));

    printf("%d\n", sol);
    return 0;
}
