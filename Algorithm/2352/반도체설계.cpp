#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

constexpr int MAX_NUM = 40010;
int n, len = 1;
int arr[MAX_NUM];
int dp[MAX_NUM];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[len] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		if (dp[len] < arr[i]) dp[++len] = arr[i];
		else {
			int idx = lower_bound(dp + 1, dp + len + 1, arr[i]) - dp;
			dp[idx] = arr[i];
		}
	}
	
	cout << len;
	return 0;
}