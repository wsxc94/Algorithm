#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int dp[1000001];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n = 5;
	vector<int> money = { 1,2,5 };
	dp[0] = 1;

	for (int m : money) {
		for (int i = m; i <= n; i++) {
			dp[i] += dp[i - m];
			dp[i] %= 1000000007;
		}
	}

	cout << dp[n] << "\n";

	return 0;
}