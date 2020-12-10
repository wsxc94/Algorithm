#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

vector<int> dy(100001, 0);
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, w, cost;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> w >> cost;

		for (int j = w; j <= m; j++)
		{
			dy[j] = max(dy[j], dy[j - w] + cost);
		}
	}
	cout << dy[m] << "\n";

	return 0;
}