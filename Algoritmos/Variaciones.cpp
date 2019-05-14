#include <iostream>
#include <deque>
using namespace std;

int n, p, A[100], cv;
bool mark[100];
deque <int> sol;

void dfs(int c) {
    for(int i = 1; i <= n; i++) {
        if(!mark[i] && c < p) {
			sol.push_back(A[i]);

            mark[i] = true;
			dfs(c + 1);
			mark[i] = false;

			if(sol.size() == p) {
				deque <int> :: iterator i;
				for(i = sol.begin(); i != sol.end(); i++)
					cout << *i << " ";
				cout << endl;
			}
				
			sol.pop_back();
        }

        else if(c == p) {
            cv++;
            return;
        }
    }
}

int main() {
    freopen("dfs.in", "r", stdin);
    freopen("dfs.out", "w", stdout);

    cin >> n >> p;
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    dfs(0);
    cout << cv << endl;
    return 0;
}
