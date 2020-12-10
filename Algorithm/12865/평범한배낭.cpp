#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

vector<int> d(100001, 0);
vector<int> weight(101);
vector<int> cost(101);
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i] >> cost[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			if (j >= weight[i]) d[j] = max(d[j], d[j - weight[i]] + cost[i]);
		}
	}
	cout << d[m] << "\n";

	return 0;
}