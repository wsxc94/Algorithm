#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

int n;
vector<int> num(13, 0);
vector<bool> ch(13, false);

void dfs(int cnt , string ans , int idx) {
	if (cnt == 7) {
		cout << ans << "\n";
	}
	else {
		for (int i = idx; i < n; i++)
		{
			if (ch[i]) continue;
			ch[i] = true;
			dfs(cnt + 1, ans + to_string(num[i]) + " ", i + 1);
			ch[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
			ch[i] = false;
		}
		dfs(1, "" , 0);
		cout << "\n";
	}
	return 0;
}