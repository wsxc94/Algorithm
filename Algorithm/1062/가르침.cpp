#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

/*
    k개의 알파벳을 습득 후 동시에 배울 수 있는 최대 단어의 개수에 대해 찾는 문제이다.
	알파벳 26개중 anta , tica -> a c i n t 는 이미 배운 상태이다.

	완전탐색 풀이.
*/
int n, k, ans = 0;
bool ch[26];
vector<string> s;

void wordcheck() {
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		bool cmp = false;
		for (int j = 0; j < s[i].size(); j++)
		{
			if (!ch[s[i][j] - 'a']) {
				cmp = true;
				break;
			}
		}
		if (!cmp) res++;
	}
	ans = max(ans, res);
}

void dfs(int idx, int cnt) {
	if (k == cnt) {
		wordcheck();
		return;
	}
	for (int i = idx; i < 26; i++)
	{
		if (!ch[i]) {
			ch[i] = true;
			dfs(i, cnt + 1);
			ch[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> k;

	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}
	else if (k == 26)
	{
		cout << n << "\n";
		return 0;
	}

	ch['a' - 'a'] = true;
	ch['c' - 'a'] = true;
	ch['i' - 'a'] = true;
	ch['n' - 'a'] = true;
	ch['t' - 'a'] = true;
	k -= 5;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		tmp.erase(tmp.begin() ,tmp.begin() + 4);
		tmp.erase(tmp.end() - 4 , tmp.end());
		s.push_back(tmp);
	}

	dfs(0, 0);

	cout << ans << "\n";

	return 0;
}