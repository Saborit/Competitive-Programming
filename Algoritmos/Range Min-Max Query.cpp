#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX = 101;
int M[MAX][MAX], n, s;

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> M[i][0];

    for(int j = 1; j <= log2(n); j++) {
        int p = 1 << (j - 1);
        s += p;

        for(int i = 1; i <= n - s; i++)
            M[i][j] = max(M[i][j - 1], M[i + p][j - 1]);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        int d = log2(b - a);

        b = b - (1 << d) + 1;
        cout << max(M[a][d], M[b][d]) << endl;
    }

    return 0;
}
