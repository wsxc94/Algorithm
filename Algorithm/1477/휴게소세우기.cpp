#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, len;

int returnValue(vector<int>& v , int dist) {

	int res = 0;

	for (int i = 1; i < v.size(); i++)
		res += (v[i] - v[i - 1] - 1) / dist;

	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> len;
	vector<int> restArea;

	restArea.reserve(n + 3);

	restArea.push_back(0);
	restArea.push_back(len);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		restArea.push_back(num);
	}

	sort(restArea.begin(), restArea.end());

	int l = 0, r = len, mid;

	while (l <= r)
	{
		mid = (l + r) / 2;

		if (returnValue(restArea, mid) > m) l = mid + 1;
		else r = mid - 1;

	}

	cout << l << "\n";

	return 0;
}