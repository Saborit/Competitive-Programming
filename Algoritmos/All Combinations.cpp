#include <iostream>
using namespace std;

int n, A[100], l, sol;

int main() {
    cin >> n;
    l = 1 << n;

    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 1; i < l; i++) {
        int s = 0;
        for(int j = 0; j < n; j++)
            if(i & 1 << j) s += A[j];
        sol = max(sol, s);
    }

    cout << sol << endl;
    return 0;
}
