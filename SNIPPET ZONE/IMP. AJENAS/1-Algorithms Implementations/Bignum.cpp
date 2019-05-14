/*
Luis Enrique Bernal Fuentes
Algorithm: Bignum
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, ln, ln1, d, m, r, tot, d1, S[100];
char n[100], n1[100];

int conv (char a) {
	return a - 48;
}

int main() {
	scanf ("%s %s", &n, &n1);
	
	ln = strlen (n) - 1;
	ln1 = strlen (n1) - 1;
	for (i = ln1; i >= 0; i--) {
		d = conv(n1[i]);
		m = ln1 - i;
		for (j = ln; j >= 0; j--) {
			d1 = conv (n[j]);
			tot = d1 * d;
			r = tot % 10;
			S[m] = (S[m] + r) % 10;
			S[++m] += tot / 10;
		}
	}

    for (i = m - 1; i >= 0; i--)
        printf ("%d", S[i]);
	
	system ("pause");
	
	return 0;
}
