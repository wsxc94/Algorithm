#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie
{
	int cnt;
	bool terminal;
	Trie* next[11];

	Trie() : terminal(false), cnt(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {

		for (int i = 0; i < 10; i++)
		{
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == 0) {
			terminal = true;
		}
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			next[cur]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == 0) return true;
		if (terminal) return false;

		int cur = *key - '0';
		return next[cur]->find(key + 1);
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t, n;
	vector<string> target(10000);
	cin >> t;

	while (t--)
	{
		Trie trie;
		bool cmp = false;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> target[i];
			trie.insert(target[i].c_str());
		}

		for (int i = 0; i < n; i++)
		{
			if (!trie.find(target[i].c_str())) {
				cmp = true;
				break;
			}
		}

		if (cmp) cout << "NO" << "\n";
		else cout << "YES" << "\n";

	}
	return 0;
}