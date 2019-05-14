#include <cstdio>
#include <algorithm>
using namespace std;

int sini, send, i, j, l, b, dec, r;
char n[100], sol[100];

void decimal() {
	for (i = l; i >= 0; i--) {
		n[i] -= 48;
		if (n[i] >= 10)
			n[i] -= 7;
		dec += n[i] * b;
		b *= sini;
	}
}

void sistem() {
	while (dec != 0) {
		r = dec % send;
		dec /= send;
		if (r >= 10)
			r += 7;
		r += 48;
		sol[i] = r;
		i++;
	}
}

int main() {
	scanf ("%s %d %d", &n, &sini, &send);
	
	l = strlen(n) - 1;
	b = 1;
	decimal();
	i = 0;
	sistem();
	
	for (j = i - 1; j >= 0; j--)
		printf ("%c", sol[j]);

    system("pause > nul");
	return 0;
}
