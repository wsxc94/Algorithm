#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
constexpr int MAX_NUM = 12;

int dp[MAX_NUM];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_NUM; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}