#include <cstdio>
#include <algorithm>
using namespace std;

int i, s, l, sol, b;
char n[20];

int main() {
	scanf ("%s %d", &n, &s);

	b = 1;
	l = strlen(n) - 1;
	for (i = l; i >= 0; i--) {
        n[i] -= 48;
        if (n[i] >= 10)
			n[i] -= 7;
		sol += n[i] * b;
		b *= s;
	}

	printf ("%d", sol);
	
	system ("pause > nul");
	return 0;
}
