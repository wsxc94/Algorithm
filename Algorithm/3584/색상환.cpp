#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
/*
    dp[n][k] = n개 짜리의 색에서 k개를 인접하지 않게 칠하는 경우의 수
*/
constexpr int MOD = 1000000003;

int dp[1003][1003];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = i;
		for (int j = 2; j <= i/2; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}

	cout << dp[n][k] << "\n";
	
	return 0;
}