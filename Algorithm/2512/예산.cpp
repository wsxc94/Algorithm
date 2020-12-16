#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, limit = 0, ans = 0;
	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		limit = max(limit, num[i]);
	}

	cin >> m;

	int l = 0, r = limit, mid;

	while (l <= r)
	{
		mid = (l + r) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++)
			sum += min(num[i], mid);

		if (sum <= m) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}

	}

	cout << ans << "\n";

	return 0;
}