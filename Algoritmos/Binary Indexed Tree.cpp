#include <cstdio>
using namespace std;

const int MAX = 50001;
int T[MAX], n, q;

int query(int x) {
	int sum = 0;

	for(; x > 0; x -= (x & -x))
		sum += T[x];

	return sum;
}

int query_at(int x) {
	return query(x) - query(x - 1);
}

void update(int x, int val) {
	for(; x <= n; x += (x & -x))
		T[x] += val;
}

int main() {
	freopen("bit.in", "r", stdin);
	freopen("bit.out", "w", stdout);

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		update(i, a);
	}

	update(4, 5);
	printf("%d", query_at(4));

	return 0;
}