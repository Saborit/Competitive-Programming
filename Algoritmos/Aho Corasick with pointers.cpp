#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 3e5 + 5;
int n, m, I[MAX], F[MAX], T[5005];
char A[MAX], s[5005];

struct node {
    node *next[26], *fail;
    vector <int> ac;

    node() {
        fail = NULL;

        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} root;

void bfs() {
    queue <node *> Q;

    node *k = &root;
    for(int i = 0; i < 26; i++) {
        if(k -> next[i] != NULL) {
            k -> next[i] -> fail = &root;
            Q.push(k -> next[i]);
        }

        else k -> next[i] = &root;
    }

    while(!Q.empty()) {
        node *p = Q.front();
        Q.pop();

        for(int c = 0; c < 26; c++) {
            node *next = p -> next[c];

            if(next == NULL)
                continue;

            node *k = p -> fail;

            while(k != &root && k -> next[c] == NULL)
                k = k -> fail;

            k = k -> next[c];
            next -> fail = k;

            for(int i = 0; i < k -> ac.size(); i++)
                next -> ac.push_back(k -> ac[i]);

            Q.push(next);
        }
    }
}

int main() {
    freopen("pop.in", "r", stdin);
    freopen("pop.out", "w", stdout);

    scanf("%d%s%d", &n, A + 1, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%s", &s);
        int l = strlen(s);
        node *k = &root;
        T[i] = l;

        for(int j = 0; j < l; j++) {
            int c = s[j] - 'a';

            if(k -> next[c] == NULL)
                k -> next[c] = new node();
            k = k -> next[c];
        }

        k -> ac.push_back(i);
    }

    bfs();

    node *k = &root;
    for(int i = 1; i <= n; i++) {
        int c = A[i] - 'a';

        while(k != &root && k -> next[c] == NULL)
            k = k -> fail;

        k = k -> next[c];

        for(int j = 0; j < k -> ac.size(); j++) {
            int id = k -> ac[j];
            int b = i;
            int a = b - T[id] + 1;
            I[a]++, F[b + 1]--;
        }
    }

    int s = 0, sol = 0;
    for(int i = 1; i <= n; i++) {
        s += I[i] + F[i];

        if(s == 0)
            sol++;
    }

    printf("%d\n", sol);
    return 0;
}
