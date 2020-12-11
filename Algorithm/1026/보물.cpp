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

	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	
	sort(a.begin(), a.end() , greater<int>());
	sort(b.begin(), b.end(), less<int>());

	for (int i = 0; i < n; i++)
	{
		ans += a[i] * b[i];
	}

	cout << ans << "\n";
	return 0;
}