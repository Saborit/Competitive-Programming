#include <cstdio>
using namespace std;

typedef long long int64;
const int
    MAX = 1e6 + 5,
    MOD = 1000000009;
int n, m, mark[4 * MAX];
int64 tree[4 * MAX], flag[4 * MAX];

void build(int x, int start, int end) {
    flag[x] = 1;

    if(start == end) {
        tree[x] = 1;
        return;
    }

    int mid = (start + end) / 2;

    build(2 * x, start, mid);
    build(2 * x + 1, mid + 1, end);

    tree[x] = tree[2 * x] + tree[2 * x + 1];
    tree[x] %= MOD;
}

void update(int x, int start, int end, int a, int b, int64 k) {
    if(mark[x]) {
        tree[x] *= flag[x];
        tree[x] %= MOD;

        if(start != end) {
            flag[2 * x] *= flag[x];
            flag[2 * x + 1] *= flag[x];

            flag[2 * x] %= MOD;
            flag[2 * x + 1] %= MOD;

            mark[2 * x] = mark[2 * x + 1] = 1;
        }

        flag[x] = 1;
        mark[x] = 0;
    }

    if(start > b || end < a)
        return;

    if(start >= a && end <= b) {
        tree[x] *= k;
        tree[x] %= MOD;

        if(start != end) {
            flag[2 * x] *= k;
            flag[2 * x + 1] *= k;

            flag[2 * x] %= MOD;
            flag[2 * x + 1] %= MOD;

            mark[2 * x] = mark[2 * x + 1] = 1;
        }

        return;
    }

    int mid = (start + end) / 2;

    update(2 * x, start, mid, a, b, k);
    update(2 * x + 1, mid + 1, end, a, b, k);

    tree[x] = tree[2 * x] + tree[2 * x + 1];
    tree[x] %= MOD;
}

int64 query(int x, int start, int end, int a, int b) {
    if(mark[x]) {
        tree[x] *= flag[x];
        tree[x] %= MOD;

        if(start != end) {
            flag[2 * x] *= flag[x];
            flag[2 * x + 1] *= flag[x];

            flag[2 * x] %= MOD;
            flag[2 * x + 1] %= MOD;

            mark[2 * x] = mark[2 * x + 1] = 1;
        }

        flag[x] = 1;
        mark[x] = 0;
    }

    if(start > b || end < a)
        return 0;

    if(start >= a && end <= b)
        return tree[x];

    int mid = (start + end) / 2;

    int left = query(2 * x, start, mid, a, b);
    int right = query(2 * x + 1, mid + 1, end, a, b);

    return (left + right) % MOD;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    while(scanf("%d%d", &n, &m) != EOF) {
        build(1, 1, n);

        while(m--) {
            int op, a, b; int64 c;
            scanf("%d%d%d", &op, &a, &b);

            if(!op) {
                scanf("%lld", &c);
                update(1, 1, n, a, b, c);
            }

            else printf("%lld\n", query(1, 1, n, a, b));
        }
    }

    return 0;
}
