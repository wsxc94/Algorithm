#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	vector<int> garosu(n);
	vector<int> dp;

	for (int i = 0; i < n; i++)
	{
		cin >> garosu[i];
	}

	for (int i = 1; i < n; i++)
	{
		dp.push_back(garosu[i] - garosu[i - 1]);
	}

	int ans = dp[0];

	for (int i = 1; i < dp.size(); i++)
	{
		ans = gcd(ans, dp[i]);
	}
	
	int len = garosu[n - 1] - garosu[0];

	cout << (len / ans) - (n - 1) << "\n";

	return 0;
}