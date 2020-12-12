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

	int n, ans = -1001;
	cin >> n;

	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
		dp[i] = max(dp[i], dp[i] + dp[i - 1]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}