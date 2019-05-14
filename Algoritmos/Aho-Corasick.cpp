//Tested on 1427 Light OJ and UVA 10679.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int
    MAXN = 1e6 + 5,
    MAXM = 505,
    MAXS = 250005;
int n, t, q, C[MAXM], f[MAXS], trie[MAXS][26];
char A[MAXN], s[MAXM];
vector <int> ac[MAXS];
queue <int> Q;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, A + 1);
        int m = strlen(A + 1);

        for(int i = 0; i <= 250000; i++) {
            f[i] = 0;
            ac[i].clear();

            for(int j = 0; j < 26; j++)
                trie[i][j] = -1;
        }

        for(int i = 1; i <= 500; i++)
            C[i] = 0;

        int sz = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", &s);
            int l = strlen(s);
            int k = 0;

            for(int j = 0; j < l; j++) {
                int c = s[j] - 'a';

                if(trie[k][c] == -1)
                    trie[k][c] = ++sz;
                k = trie[k][c];
            }

            ac[k].push_back(i);
        }

        for(int i = 0; i < 26; i++) {
            if(trie[0][i] == -1)
                trie[0][i] = 0;

            else Q.push(trie[0][i]);
        }

        while(!Q.empty()) {
            int p = Q.front();
            Q.pop();

            for(int c = 0; c < 26; c++) {
                if(trie[p][c] == -1)
                    continue;

                int k = f[p];

                while(k > 0 && trie[k][c] == -1)
                    k = f[k];

                k = trie[k][c];
                f[trie[p][c]] = k;

                for(int i = 0; i < ac[k].size(); i++)
                    ac[trie[p][c]].push_back(ac[k][i]);

                Q.push(trie[p][c]);
            }
        }

        int k = 0;
        for(int i = 1; i <= m; i++) {
            int c = A[i] - 'a';

            while(k > 0 && trie[k][c] == -1)
                k = f[k];

            k = trie[k][c];

            for(int j = 0; j < ac[k].size(); j++)
                C[ac[k][j]]++;
        }

        printf("Case %d:\n", ++q);
        for(int i = 1; i <= n; i++)
            printf("%d\n", C[i]);
    }

    return 0;
}
