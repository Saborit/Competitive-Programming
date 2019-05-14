#include <iostream>
#include <string>
using namespace std;

int n;

struct node {
	node *next[26];
	int mk;
} root;

int main() {
	freopen("trie.in", "r", stdin);
	freopen("trie.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s; cin >> s;

		node *k = &root;

		for(int j = 0; j < s.size(); j++) {
			int p = s[j] - 'a';

			if(k -> next[p] == NULL)
				k -> next[p] = new node();
			k = k -> next[p];
		}

		k -> mk = 1;
	}

	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s; cin >> s;

		node *k = &root;
		bool loc = true;

		for(int j = 0; j < s.size(); j++) {
			int p = s[j] - 'a';

			if(k -> next[p] == NULL) {
				loc = false;
				break;
			}

			k = k -> next[p];
		}

		if(loc && k -> mk) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}