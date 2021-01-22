#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;


const int NUM = 27;

int toNumber(char n) {
	if (n == '?')
	{
		return 26;
	}

	return n - 'a';
}

struct TrieNode
{
	TrieNode* children[NUM];
	bool terminal;
	int cnt;

	TrieNode() :terminal(false), cnt(0)
	{
		for (int i = 0; i < NUM; ++i)
		{
			children[i] = NULL;
		}
	}

	~TrieNode()
	{
		for (int i = 0; i < NUM; i++)
		{
			if (children[i])
			{
				delete children[i];
			}
		}
	}

	void insert(const char* key)
	{
		//키값이 널이라면
		if (*key == 0)
		{
			terminal = true;
		}
		else
		{
			int next = toNumber(*key);
			if (children[next] == NULL)
			{
				children[next] = new TrieNode();
			}

			children[next]->insert(key + 1);
		}
	}

	void find(const char* key)
	{
		if (*key == 0)
		{
			cnt++;
			return;
		}

		int next = toNumber(*key);
		if (children[toNumber('?')] != NULL)
		{
			children[toNumber('?')]->find(key + 1);
		}

		if (children[next] != NULL)
		{
			children[next]->find(key + 1);
		}
	}

	int getCnt(const char* key)
	{
		if (*key == 0)
		{
			return cnt;
		}

		int next = toNumber(*key);
		if (children[next] == NULL)
		{
			return 0;
		}

		return children[next]->getCnt(key + 1);
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> words = { "frodo" , "front" , "frost" , "frozen" , "frame" , "kakao" };

	vector<string> queries = { "fro??" , "????o" , "fr???" , "fro???" , "pro?" };
	
	vector<int> answer;

	TrieNode trie;

	for (int i = 0; i < queries.size(); ++i)
	{
		trie.insert(queries[i].c_str());
	}

	for (int i = 0; i < words.size(); ++i)
	{
		trie.find(words[i].c_str());
	}

	for (int i = 0; i < queries.size(); ++i)
	{
		answer.push_back(trie.getCnt(queries[i].c_str()));
	}

	for (auto a : answer)
	{
		cout << a << " ";
	}

	return 0;
}