#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int n, k, A[MAX];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);

        int top = 0;
        for(int i = 1; i <= n; i++) {
            int num; scanf("%d", &num);

            if(num > A[top])
                A[++top] = num;

            else {
                int p = lower_bound(A + 1, A + top + 1, num) - A;
                A[p] = num;
            }
        }

        printf("%d\n", top);
    }

    return 0;
}
