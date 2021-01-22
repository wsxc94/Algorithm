#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie
{
	int cnt;
	bool term;
	Trie* next[26];

	Trie() : term(false) , cnt(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
		{
			if (next[i]) delete next[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') term = true;
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL) next[cur] = new Trie();
			else next[cur]->cnt++;

			next[cur]->insert(key + 1);	
		}
	}

	int find(const char* key) {
		int cur = *key - 'a';
		if (*key == '?') {
			int tmp = 0;
			for (int i = 0; i < 26; i++)
			{
				if (next[i] != NULL) tmp += next[i]->cnt;
			}
			return tmp;
		}

		if (next[cur] == NULL) return 0;
		if (*(key + 1) == '?') return next[cur]->cnt;
		return next[cur]->find(key + 1);
	}

};

Trie *root[10001];
Trie *reRoot[10001];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> words = { "frodo" , "front" , "frost" , "frozen" , "frame" , "kakao" };

	vector<string> queries = { "fro??" , "????o" , "fr???" , "fro???" , "pro?" };
	

	int wsize = words.size();
	int qsize = queries.size();
	vector<int> answer(qsize, 0);
	
	for (string &w : words)
	{
		int len = w.size();

		const char* c = w.c_str();
		if (root[len] == NULL) root[len] = new Trie();
		root[len]->insert(c);

		string reverse = w;
		std::reverse(w.begin(), w.end());

		const char* k = w.c_str();
		if (reRoot[len] == NULL) reRoot[len] = new Trie();
		reRoot[len]->insert(k);
	}

	int idx = 0;

	for (string &q : queries)
	{
		int len = q.size();

		if (q[len - 1] == '?') {
			const char* c = q.c_str();

			if (root[len] == NULL) { idx++; continue; }
			else answer[idx] = root[len]->find(c);
		}
		else {
			string re = q;
			std::reverse(re.begin(), re.end());
			const char *k = re.c_str();

			if (reRoot[len] == NULL) { idx++; continue; }
			else answer[idx] = reRoot[len]->find(k);
		}
		idx++;
	}

	for (auto a : answer)
	{
		cout << a << " ";
	}

	return 0;
}