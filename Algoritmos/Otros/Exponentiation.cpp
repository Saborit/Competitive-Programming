#include <iostream>
using namespace std;

typedef unsigned long long ull;
ull a, n;

ull sq(ull n) {
    return n * n;
}

int exp(ull a, ull n) {
    if(n == 1) return a;

    if(n % 2) return exp(a, n - 1) * a;
    else return sq(exp(a, n / 2));
}

int main() {
    cin >> a >> n;

    cout << exp(a, n) << endl;
    return 0;
}
