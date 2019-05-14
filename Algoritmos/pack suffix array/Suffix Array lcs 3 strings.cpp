//tested on 1347 LOJ

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 15005;
int t, a, b, c, n, tc, sa[MAX], ra[MAX], tsa[MAX], tra[MAX], f[MAX], last[MAX], lcp[MAX], lcp_[MAX], lg[MAX], m[MAX][20];
char s[MAX], s1[MAX], s2[MAX], s3[MAX];

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

		while(s[i + l] == s[last[i] + l])
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

int exLcp(int i, int j) {
	if(i > j)
		return 0;

	int k = lg[j - i + 1];
	return min(m[i][k], m[j - (1 << k) + 1][k]);
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	for(int i = 1; i <= 15000; i++)
		lg[i] = log2(i);

	scanf("%d", &t);
	while(t--) {
		scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
		a = strlen(s1 + 1);
		b = strlen(s2 + 1);
		c = strlen(s3 + 1);

		n = 0;
		for(int i = 1; i <= a; i++) {
			n++;
			sa[n] = n;
			ra[n] = s1[i];
			s[n] = s1[i];
		}

		for(int i = 1; i <= b; i++) {
			n++;
			sa[n] = n;
			ra[n] = s2[i];
			s[n] = s2[i];
		}

		for(int i = 1; i <= c; i++) {
			n++;
			sa[n] = n;
			ra[n] = s3[i];
			s[n] = s3[i];
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

		for(int i = 1; i <= n; i++)
			m[i][0] = lcp[i];

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= lg[n]; j++)
				m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);

		int x, y, z; x = y = z = -1;
		int sol = 0;
		for(int i = 1; i <= n; i++) {
			if(n - sa[i] + 1 <= c)
				z = i;

			else if(n - sa[i] + 1 <= b + c)
				y = i;

			else x = i;

			int p = min(x, min(y, z));

			if(p == -1)
				continue;

			int q = exLcp(p + 1, i);
			int tmp = min(a - sa[x], min(a + b - sa[y], n - sa[z]));
			q = min(q, tmp + 1);
			sol = max(sol, q);
		}

		printf("Case %d: %d\n", ++tc, sol);

		int l = max(300, n); //this is really important
		for(int i = 0; i <= l; i++) {
			sa[i] = ra[i] = tsa[i] = tra[i] = 0;
			f[i] = last[i] = lcp[i] = lcp_[i] = 0;
		}

		for(int i = 0; i <= n; i++)
			for(int j = 0; j < 20; j++)
				m[i][j] = 0;
	}

	return 0;
}

