#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, ans = 0;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 6;
	dp[1] = arr[0] + arr[1];

	for (int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1] - arr[i - 2]);
		ans = max(ans, dp[i]);
	}


	return 0;
}