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

	priority_queue<int,vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	while (q.size() > 1)
	{
		int l = q.top();
		q.pop();
		int r = q.top();
		q.pop();

		ans += l + r;
		q.push(l + r);
	}

	cout << ans;
	return 0;
}