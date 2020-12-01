#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	int dp[1001][3] = { 0, };

	int cost[3];

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = cost[0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[2] + min(dp[i - 1][1], dp[i - 1][0]);
		//cout<<"ÃÖ¼Ò°ª : " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}