#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int dp(int& n) {
	int l = 1, r = 1;

	for (int i = 2; i <= n; i++)
	{
		int ans = (l + r) % 15746;
		l = r, r = ans;
	}
	return r;
	
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	cout << dp(n);

	return 0;
}