#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
int n, a, Td[MAX], low[MAX], t, Ap[MAX];
vector <int> G[MAX];

void dfs(int nod) {
	Td[nod] = low[nod] = ++t;

	for(int i = 0; i < G[nod].size(); i++) {
		int newn = G[nod][i];

		if(!low[newn]) {
			dfs(newn);
			low[nod] = min(low[nod], low[newn]);

			if(Ap[nod]) continue;

			if((Td[nod] == 1 && Td[newn] > 2) || (Td[nod] != 1 && Td[nod] <= low[newn]))
				Ap[nod] = 1;
		}

		else low[nod] = min(low[nod], Td[newn]);
	}
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	cin >> n >> a;
	for(int i = 1; i <= a; i++) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);

	for(int i = 1; i <= n; i++)
		if(Ap[i]) cout << i << endl;

	return 0;
}