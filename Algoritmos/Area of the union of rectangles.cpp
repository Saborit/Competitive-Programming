#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long huge;
const int MAX = 1001 * 2;
int n, k;
huge sol;

struct range {
    huge x, y0, y;
    int flag;

    range() {}

    range(huge a, huge b, huge c, int d) {
        x = a, y0 = b, y = c, flag = d;
    }

    bool operator < (const range &r) const {
        if(x != r.x)
            return x < r.x;
        return flag > r.flag;
    }
} A[MAX];

struct par {
    huge y;
    int flag;

    par(huge a, int b) {
        y = a, flag = b;
    }

    bool operator < (const par &p) const {
        if(y != p.y)
            return y < p.y;
        return flag > p.flag;
    }
};

multiset <par> S;
multiset <par> :: iterator p;

huge height() {
    huge dy = 0, y0 = 0;
    int l = 0;

    for(p = S.begin(); p != S.end(); p++) {
        l += p -> flag;

        if(p -> flag == 1 && l == 1)
            y0 = p -> y;

        if(!l) dy += p -> y - y0;
    }

    return dy;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        huge x0, y0, x, y;
        scanf("%lld%lld%lld%lld", &x0, &y0, &x, &y);

        if(y0 > y)
            swap(y0, y);

        A[++k] = range(x0, y0, y, 1);
        A[++k] = range(x, y0, y, -1);
    }

    sort(A + 1, A + k + 1);

    S.insert(par(A[1].y0, 1));
    S.insert(par(A[1].y, -1));

    huge x0 = A[1].x;
    huge dy = height();

    for(int i = 2; i <= k; i++) {
        sol += dy * (A[i].x - x0);

        if(A[i].flag == 1) {
            S.insert(par(A[i].y0, 1));
            S.insert(par(A[i].y, -1));
        }

        else {
            S.erase(S.find(par(A[i].y0, 1)));
            S.erase(S.find(par(A[i].y, -1)));
        }

        x0 = A[i].x, dy = height();
    }

    printf("%lld\n", sol);
    return 0;
}

