/*
Luis Enrique Bernal Fuentes
Algorithm: All Combinations
Descriptions: Halla todas las Combinaciones posibles
*/

#include <cstdio>
#include <string>

#define RANG 25
#define P (1 << lT)
using namespace std;

int lT;
char T[RANG];
string C;

int main() {
	freopen ("all combinations.in", "r", stdin);
	freopen ("all combinations.out", "w", stdout);

	scanf ("%s", &T);
	
	lT = strlen (T);
	printf ("%d\n", P - 1);
	for (int i = 1; i < P; i++) {
		C = "";
		for (int j = 0; j < lT; j++)
			if (i & 1 << j)
				C += T[j];
		printf ("%s\n", C.c_str());
	}
	
	return 0;
}
