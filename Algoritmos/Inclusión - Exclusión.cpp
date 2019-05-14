#include <iostream>
using namespace std;

int n, k, sol, l, D[10];

int mcd(int a, int b) {
	int r = 1;

	while(r > 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int mcm(int a, int b) {
	return a * b / mcd(a, b);
}

int main() {
	freopen("death.in", "r", stdin);
	freopen("death.out", "w", stdout);

	cin >> n >> k;
	for(int i = 0; i < k; i++)
		cin >> D[i];

	l = 1 << k;
	for(int i = 1; i < l; i++) {
		int m = 1, d = 0;

		for(int j = 0; j < n; j++)
			if(i & 1 << j) m = mcm(m, D[j]), d++;

		if(d & 1) sol += n / m;
		else sol -= n / m;
	}

	cout << n - sol << endl;
	return 0;
}
