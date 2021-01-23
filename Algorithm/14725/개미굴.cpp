#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

map<string, int> trie[15001];
int trie_size = 0;

void t_insert(const vector<string>& vs) {
	int cnt = 0;

	for (auto& s : vs)
	{
		if (trie[cnt].find(s) == trie[cnt].end()) {
			trie[cnt][s] = ++trie_size;
			cnt = trie_size;
		}
		else cnt = trie[cnt][s];
	}
}

void t_print(int cnt, int depth) {
	for (auto& t : trie[cnt])
	{
		cout << string(depth * 2, '-') << t.first << "\n";
		t_print(t.second, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		vector<string> s(k);
		for (int j = 0; j < k; j++)
		{
			cin >> s[j];
		}
		t_insert(s);
	}

	t_print(0, 0);

	return 0;
}