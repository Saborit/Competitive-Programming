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
} a[100];

bool com (const tri &p, const tri &s) {
        if (s.x != p.x)
            return s.x < p.x;
        if (s.y != p.y)
            return s.y < p.y;
        return s.z < p.z;
    }
   

int main(){
	freopen ("struct.in", "r", stdin);
	freopen ("struct.out", "w", stdout);
	
	scanf("%d\n",&n);\
  	for (i = 0; i < n; i++) {
    	scanf("%d%d%d",&x,&y,&z);
		a[i] = tri(x, y, z);
  	}
 	
	sort (a, a + n, com);
  	for (i = 0; i < n; i++)
		printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);
	 
	return 0; 
}
