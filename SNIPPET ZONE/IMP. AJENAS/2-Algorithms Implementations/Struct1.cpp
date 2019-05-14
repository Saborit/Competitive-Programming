#include <cstdio>
#include <algorithm>
using namespace std;

int i, x, y, z, n;

struct tri {
    int x, y, z;
    
    tri (int a = 0, int b = 0, int c = 0) {
        x = a;
        y = b;
        z = c;
    }

    bool operator < (const tri &p) const {
        if (x != p.x)
            return x < p.x;
        if (y != p.y)
            return y < p.y;
        return z < p.z;
    }
} a[100];


int main() {
    freopen ("struct.in", "r", stdin);
    freopen ("struct.out", "w", stdout);

    scanf ("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf ("%d %d %d", &x, &y, &z);
        a[i] = tri (x, y, z);
    }
    
    sort (a + 1, a + n + 1);
    
    for (i = 1; i <= n; i++)
        printf ("%d %d %d\n", a[i].x, a[i].y, a[i].z);
 
    return 0;
}
