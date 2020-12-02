#include <iostream>
#include <vector>

using namespace std;

constexpr int Mod = 1000000000;
int dp[101][10];

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	long long sum = 0;
	int n;
	cin >> n;

	for (int i = 1; i <=9; i++)
	{
		dp[1][i] = 1;
	}

	// 0 은 1밖에 올수 없고
	// 9 는 8밖에 올수 없다
	// 나머지는 -1 +1 범위만큼 가능

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
		}
	}

	for (int i = 0; i <= 9; i++) sum += dp[n][i];
	cout << sum % Mod<< "\n";
	return 0;
}