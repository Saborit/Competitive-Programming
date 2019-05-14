#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 20001;
int n, a, P[MAX], T[MAX], sol;

struct edge {
	int ni, nf, cost;

	edge() {}

	edge(int a, int b, int c) {
		ni = a, nf = b, cost = c;
	}

	bool operator < (const edge &e) const {
		return cost < e.cost;
	}
} A[MAX];

int find_set(int x) {
	if(x == P[x])
		return x;

	P[x] = find_set(P[x]);
}

void join_sets(int a, int b) {
	if(T[a] < T[b])
		swap(T[a], T[b]);

	P[b] = a;
	T[a] += T[b];
}

int main() {
	freopen("kruskal.in", "r", stdin);
	freopen("kruskal.out", "w", stdout);

	cin >> n >> a;
	for(int i = 1; i <= a; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A[i] = edge(a, b, c);
	}

	for(int i = 1; i <= n; i++)
		P[i] = i, T[i] = 1;

	sort(A + 1, A + a + 1);
	for(int i = 1; i <= a; i++) {
		edge e = A[i];
		int a = find_set(e.ni);
		int b = find_set(e.nf);

		if(a != b) {
			sol += e.cost;
			join_sets(a, b);
		}
	}

	cout << sol << endl;
	return 0;
}
