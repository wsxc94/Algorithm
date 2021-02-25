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
    n = 2 -> ans = 1
	n = 4 -> ans = 2
	n = 6 -> ans = 5
	n = 8 -> ans = 14

	카탈란 수의 규칙을 가지고 있다.

	카탈란 수 C(i) = (2i)  -  (2i)
	                 (i)     (i+1)

	
*/
constexpr int MOD = 987654321;
int n;
long long dp[5001];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n;

	dp[0] = 1;

	for (int i = 1; i <= n/2; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD;
		}
	}

	cout << dp[n / 2] << "\n";

	return 0;
}