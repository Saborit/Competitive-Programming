#include <cstdio>
#include <algorithm>
using namespace std;

long long t, i;
double n, d, pi;

int main() {
    scanf ("%I64d", &t);
    
    pi = 1;
    n = 2; d = 3;
    pi *= (n / d);
    for (i = 2; i <= t; i++) {
        if (i % 2 == 0)
           n += 2;
        else
            d+= 2;
        pi *= (n / d);    
    }    
    
    printf ("%fl", pi * 4);
    
    system ("pause > nul");
    return 0;
}
