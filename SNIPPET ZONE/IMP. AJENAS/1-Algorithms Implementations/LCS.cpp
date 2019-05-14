/*
Name: Luis Enrique Bernal Fuentes
Grade: 11no 5
Algorithm: LCS
(Halla la subsecuencia común más larga)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, c, la, lb, Dp[100][100];
char a[100], b[100];

int main() {
	freopen ("lcs.in", "r", stdin);
	freopen ("lcs.out", "w", stdout);
	
    scanf ("%d %d\n", &la, &lb);
    for (i = 1; i <= la; i++)
        scanf ("%c", &a[i]);
    scanf ("\n");
    for (i = 1; i <= lb; i++)
        scanf ("%c", &b[i]);
	
	for (i = 1; i <= lb; i++) {
		for (j = 1; j <= la; j++) {
			c = Dp[i][j - 1];
			c >?= Dp[i - 1][j];
			if (b[i] == a[j])
				c++;
			Dp[i][j] = c;
		}
	}
    
	printf ("%d", Dp[lb][la]);

	return 0;
}
