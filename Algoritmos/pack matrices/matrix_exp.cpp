#include <cstdio>
#include <vector>
using namespace std;

typedef vector <vector <int> > matrix;
int n, m, k;

matrix mul(matrix A, matrix B, int n, int m, int k) {
    matrix C(n + 1, vector <int> (k + 1));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            for(int l = 1; l <= m; l++)
                C[i][j] += A[i][l] * B[l][j];

    return C;
}

matrix exp(matrix A, int e) {
    if(e == 1)
        return A;

    if(e % 2)
        return mul(A, exp(A, e - 1), n, m, m);

    matrix S = exp(A, e / 2);
    S = mul(S, S, n, m, m);

    return S;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    matrix A(n + 1, vector <int> (m + 1));
    matrix B(m + 1, vector <int> (k + 1));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= k; j++)
            scanf("%d", &B[i][j]);

    matrix C = exp(A, 2);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++)
            printf("%d ", C[i][j]);
        printf("%d\n", C[i][m]);
    }

    return 0;
}

/*
IN:
3 3 1
0 1 0
0 0 1
2 2 2

3
9
26

OUT:
0 0 1
2 2 2
4 6 6
*/
