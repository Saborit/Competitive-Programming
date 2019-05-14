/*
Luis Enrique Bernal Fuentes
Algorithm: Trabajar con Stack 
*/

#include <cstdio>
#include <stack>
using namespace std;

int n, i;
char a;
stack < char > pil;

int main() {
	freopen ("pila.in", "r", stdin);
	freopen ("pila.out", "w", stdout);
	
	scanf ("%d\n", &n);
	for (i = 1; i <= n; i++) {
	    scanf ("%c", &a);
		   if (!pil.empty() && pil.top() != a)
			     pil.pop();
     else
			      if (a == '(') pil.push(a);
			      else break;
	}
	
	if (!pil.empty()) 
	   printf ("wrong");
	else
	    printf ("ok");
		
	return 0;
}
