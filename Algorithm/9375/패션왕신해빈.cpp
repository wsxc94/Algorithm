#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, t, ans;
	cin >> n;

	unordered_map<string, int> m;

	while (n--)
	{
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			string fir , second;
			cin >> fir >> second;
			m[second]++;
		}
		ans = 1;
		for (auto item : m)
		{
			ans *= item.second + 1;
		}
		cout << ans - 1 << "\n";
		m.clear();

	}
	return 0;
}