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

int dp[600002] = { 0, };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n = 4;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;


	cout << dp[n] << "\n";
	return 0;
}