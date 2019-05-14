/*
Luis Enrique Bernal Fuentes
Algorithm: Char (Algunas cosas sobre cadenas de caracter)
*/

#include <cstdio>
#include <string>
using namespace std;

int c;
char a[100], b[100];

int main() {
    scanf ("%s %s", &a, &b);
    
    //Compara
    if (!strcmp(a, b))
        printf ("Son Iguales\n");

    strcat(a, b);//Concatena
    printf ("%s\n", a);

    strcpy (b, a);//Copy
    printf ("%s\n", b);

    system ("pause");
    return 0;
}
