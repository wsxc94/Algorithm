#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int max_num = 501;

int dp[max_num][max_num] = { 0, };
int arr[max_num][max_num] = { 0, };

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	int n, ans = -9999;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}