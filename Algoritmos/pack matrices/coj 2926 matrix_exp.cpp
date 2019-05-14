#include <cstdio>
#include <vector>
using namespace std;

typedef vector <vector <int> > matrix;
const int MOD = 10007;
int e;

matrix mul(matrix A, matrix B) {
    matrix C(4, vector <int> (4));

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            for(int l = 1; l <= 3; l++)
                C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % MOD;

    return C;
}

matrix exp(matrix A, int e) {
    if(e == 1)
        return A;

    if(e % 2)
        return mul(A, exp(A, e - 1));

    matrix S = exp(A, e / 2);
    S = mul(S, S);

    return S;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    while(1) {
        scanf("%d", &e);

        if(!e) break;

        matrix A(4, vector <int> (4));
        matrix B(4, vector <int> (2));

        A[1][1] = 0, A[1][2] = 1, A[1][3] = 0;
        A[2][1] = 0, A[2][2] = 0, A[2][3] = 1;
        A[3][1] = A[3][2] = A[3][3] = 2;

        B[1][1] = 3, B[2][1] = 9, B[3][1] = 26;

        if(e < 4) {
            printf("%d\n", B[e][1]);
            continue;
        }

        matrix C = exp(A, e - 3);
        C = mul(C, B);

        printf("%d\n", C[3][1]);
    }

    return 0;
}
