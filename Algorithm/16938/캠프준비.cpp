#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int  N, L, R, X, ans;

int problem[16];
bool ch[16];
vector<int> v;

// N개의 문제에서 문제난이도의 합은 L <= , R >=
// 그리고 가장 어려운 문제와 쉬운문제의 난이도 차이는 X <= 다. 

void dfs(int idx, int cnt, int sum) {

	if (cnt >= 2) {
		int MIN_NUM = 987654321;
		int MAX_NUM = -987654321;
		int SUM = 0;

		for (int i = 0; i < v.size(); i++)
		{
			SUM += problem[v[i]];
			MIN_NUM = min(MIN_NUM, problem[v[i]]);
			MAX_NUM = max(MAX_NUM, problem[v[i]]);
		}
		if (L <= SUM && R >= SUM && MAX_NUM - MIN_NUM >= X) ans++;
	}

	for (int i = idx; i < N; i++)
	{
		if (ch[i]) continue;

		if (sum + problem[i] <= R) {
			ch[i] = true;
			v.push_back(i);
			dfs(i, cnt + 1, sum + problem[i]);
			ch[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> L >> R >> X;
	
	for (int i = 0; i < N; i++)
	{
		cin >> problem[i];
	}

	dfs(0, 0, 0);

	cout << ans << "\n";
	return 0;
}