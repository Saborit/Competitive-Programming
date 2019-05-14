#include <iostream>
#include <cstdio>
using namespace std;

int C[100], k, N;

int main() {
    freopen("cc.in", "r", stdin);
    freopen("cc.out", "w", stdout);

    cin >> k >> N; C[0] = 1;
    for(int i = 1; i <= k; i++) {
        int n1; cin >> n1;
        for(int j = n1; j <= N; j++)
            C[j] += C[j - n1];
    }

    cout << C[N] << endl;
    return 0;
}
