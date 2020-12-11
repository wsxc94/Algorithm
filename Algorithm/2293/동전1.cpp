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

	int n, cost, cnt = 0;
	cin >> n >> cost;

	vector<int> coin(100,0);
	vector<int> dp(10001,0);

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= cost; j++)
		{
			dp[j] += dp[j - coin[i]];
		}

	}

	cout << dp[cost] << "\n";
	return 0;
}