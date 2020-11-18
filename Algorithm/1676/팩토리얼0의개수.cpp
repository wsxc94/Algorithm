#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}