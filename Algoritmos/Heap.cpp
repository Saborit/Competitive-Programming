#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1000001;
int n, T[MAX * 4];

void insert(int x) {
	while(T[x] > T[x / 2] && x / 2 > 0) {
		swap(T[x], T[x / 2]);
		x /= 2;
	}
}

void remove(int x) {
    while(true) {
        int p = T[2 * x] > T[2 * x + 1] ? 2 * x : 2 * x + 1;

        if(T[p] > T[x])
            swap(T[p], T[x]), x = p;
        else return;
    }
}

int main() {
	freopen("heap.in", "r", stdin);
	freopen("heap.out", "w", stdout);

	scanf("%d\n", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d\n", &T[i]);
		insert(i);
	}

	for(int i = n; i > 0; i--) {
		printf("%d\n", T[1]);
		T[1] = T[i]; T[i] = 0;
		remove(1);
	}

	return 0;
}