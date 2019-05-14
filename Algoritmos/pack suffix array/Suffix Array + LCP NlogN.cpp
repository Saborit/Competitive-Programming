//Tested on 1314 and 1428 LOJ.

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long int64;
const int MAX = 10005;
int n, t, x, y, l, sa[MAX], ra[MAX], tsa[MAX], tra[MAX], f[MAX], last[MAX], lcp[MAX], lcp_[MAX];
char a[MAX];

void csort(int k) {
	int m = max(300, n);

	for(int i = 0; i <= m; i++)
		f[i] = 0;

	for(int i = 1; i <= n; i++) {
		int v = i + k > n ? 0 : ra[i + k];
		f[v]++;
	}

	for(int i = 0, s = 0; i <= m; i++) {
		int tmp = f[i];
		f[i] = s + 1;
		s += tmp;
	}

	for(int i = 1; i <= n; i++) {
		int v = sa[i] + k > n ? 0 : ra[sa[i] + k];
		tsa[f[v]] = sa[i];
		f[v]++;
	}

	for(int i = 1; i <= n; i++)
		sa[i] = tsa[i];
}

bool cmp(int k, int x) {
	if(ra[sa[x]] != ra[sa[x - 1]])
		return 0;

	if(sa[x] + k > n && sa[x - 1] + k > n)
		return 1;

	if(sa[x] + k > n || sa[x - 1] + k > n)
		return 0;

	if(ra[sa[x] + k] == ra[sa[x - 1] + k])
		return 1;

	return 0;
}

void getLcp() {
	last[1] = 0;
	for(int i = 2; i <= n; i++)
		last[sa[i]] = sa[i - 1];

	for(int i = 1, l = 0; i <= n; i++) {
		if(last[i] == 0) {
			lcp[i] = 0;
			continue;
		}

		while(a[i + l] == a[last[i] + l])
			l++;

		lcp_[i] = l;
		l = max(l - 1, 0);
	}

	for(int i = 1; i <= n; i++)
		lcp[i] = lcp_[sa[i]];
}

int F(int k) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(lcp[i] + 1 > k)
		 	 continue;

		ans += min(k, n - sa[i] + 1) - lcp[i];
	}

	return ans;
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.in", "w", stdout);

	scanf("%d", &t);
	while(t--) {
		scanf("%s%d%d", a + 1, &x, &y);
		n = strlen(a + 1);

		for(int i = 1; i <= n; i++) {
			sa[i] = i;
			ra[i] = a[i];
		}

		for(int k = 1; k <= n; k <<= 1) {
			csort(k);
			csort(0);

			int r = 0;
			tra[sa[1]] = ++r;

			for(int i = 2; i <= n; i++) {
				if(!cmp(k, i))
					++r;

				tra[sa[i]] = r;
			}

			for(int i = 1; i <= n; i++)
				ra[i] = tra[i];
		}

		getLcp();

		printf("Case %d: %d\n", ++l, F(y) - F(x - 1));

		int m = max(300, n); //this is really important
		for(int i = 0; i <= m; i++) {
			sa[i] = ra[i] = tsa[i] = tra[i] = 0;
			f[i] = last[i] = lcp[i] = lcp_[i] = 0;
		}
	}

	return 0;
}
