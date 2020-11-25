#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, x, y;

	cin >> n;

	vector<pair<int, int>> pos;

	pos.reserve(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos.push_back({ x,y });
	}
	sort(pos.begin(), pos.end(),
		[](pair<int, int> a, pair<int, int> b) -> bool {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first < b.first;
	}
	);

	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i].first << " " << pos[i].second << "\n";
	}

	return 0;
}