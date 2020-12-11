#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int,int>> card(n);
	vector<int> dp(n+1);
	for (int i = 0; i < n; i++)
	{
		card[i].first = i + 1;
		cin >> card[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (card[i].first > j) continue;
			dp[j] = max(dp[j], dp[j - card[i].first] + card[i].second);
		}
	}
	cout << dp[n] << "\n";
	


	return 0;
}