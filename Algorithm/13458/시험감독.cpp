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

	int n;
	int b, c;

	long long cnt = 0;
	cin >> n;
	vector<int> test(n);

	for (int i = 0; i < n; i++)
	{
		cin >> test[i];
	}
	cin >> b >> c;

	for (int i = 0; i < test.size(); i++)
	{
		cnt++;
		test[i] -= b;
		if (test[i] > 0) {
			cnt += (test[i] / c);
			if (test[i] % c != 0) cnt++;
		}

	}

	cout << cnt << "\n";
	return 0;
}