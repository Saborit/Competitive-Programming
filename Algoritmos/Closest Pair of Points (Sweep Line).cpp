#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int
	MAX = 101,
	oo = 1 << 30;
int n, last = 1;
float sol = oo;

struct point {
	int x, y;

	point() {}

	point(int a, int b) {
		x = a, y = b;
	}

	bool operator < (const point &p) const {
		return y < p.y;
	}
} P[MAX];

multiset <point> pc;
multiset <point> :: iterator u, l;

bool lowx(point a, point b) {
	return a.x < b.x;
}

float sq(float a) {
	return a * a;
}

float Dist(point a, point b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> P[i].x >> P[i].y;

	sort(P + 1, P + n + 1, lowx);
	pc.insert(P[1]);

	for(int i = 2; i <= n; i++) {
		for(; P[i].x - P[last].x >= sol; last++)
			pc.erase(pc.lower_bound(P[last]));

		u = pc.upper_bound(point(P[i].x, P[i].y + sol));
		l = pc.lower_bound(point(P[i].x, P[i].y - sol));

		for(; l != u; l++)
			sol = min(sol, Dist(*l, P[i]));

		pc.insert(P[i]);
	}

	cout << sol << endl;
	return 0;
}