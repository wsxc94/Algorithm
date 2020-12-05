#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, s, ans = 0;
vector<int> num(21);

void dfs(int idx, int sum) {
	
	if (sum == s && idx != 0) ans++;
	if (idx == n) return;

	for (int i = idx; i < n; i++)
	{
		dfs(i + 1, sum + num[i]);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> s;
	
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}