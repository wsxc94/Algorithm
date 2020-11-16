#include <iostream>
using namespace std;
#define MOD 10007

int dp[1001];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = k; j >= 1; j--) {
			dp[j] = dp[j - 1] % MOD + dp[j] % MOD;
			dp[j] %= MOD;
		}
	}
	cout << dp[k];
}