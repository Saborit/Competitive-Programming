#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int
    MAX = 100,
    oo = 1 << 30;
int n, a, mark[MAX], sol;

struct par {
    int nod, cost;
    par(int a, int b)
		{ nod = a, cost = b; }

    bool operator < (const par &p) const {
        return p.cost < cost;
    }
};

vector <par> G[MAX];
priority_queue <par> Q;

int main() {
    freopen("prim.in", "r", stdin);
    freopen("prim.out", "w", stdout);

    cin >> n >> a;
    for(int i = 1; i <= a; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(par(b, c));
        G[b].push_back(par(a, c));
    }

    for(Q.push(par(1, 0)); !Q.empty();) {
        int nod = Q.top().nod;

		if(mark[nod]) {
			Q.pop();
			continue;
		}

		mark[nod] = 1;
		sol += Q.top().cost;
		Q.pop();

        for(int i = 0; i < G[nod].size(); i++) {
            int newn = G[nod][i].nod;
            int newc = G[nod][i].cost;

            if(!mark[newn])
                Q.push(par(newn, newc));
        }
    }

    cout << sol << endl;
    return 0;
}
