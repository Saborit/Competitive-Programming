#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 1001;
char a[MAX], b[MAX];
int M[MAX][MAX], la, lb;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    cin >> a + 1 >> b + 1;
    la = strlen(a + 1); lb = strlen(b + 1);

    for(int i = 0; i <= max(la, lb); i++)
        M[i][0] = M[0][i] = i;

    for(int i = 1; i <= la; i++)
        for(int j = 1; j <= lb; j++)
            if(a[i] == b[j])
                M[i][j] = M[i-1][j-1];
            else M[i][j] = min(M[i-1][j], min(M[i][j-1], M[i-1][j-1])) + 1;

    cout << M[la][lb] << endl;
    return 0;
}
