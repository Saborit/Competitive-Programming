/*
Luis Enrique Bernal Fuentes
Algorithm: Decimal a cualquier sistema 
(Lleva un número de decimal al sistema que quieras)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, r, i, j;
char sol[1000];

int main() {
	scanf ("%d %d", &n, &s);
	
	while (n != 0) {
		r = n % s;
		n /= s;
        if (r >= 10)
			r += 7;
		r += 48;
		sol[i] = r;
		i++;
	}
	
    for (j = i - 1; j >= 0; j--)
		printf ("%c", sol[j]);
	
	system ("pause > nul");
	return 0;
}
