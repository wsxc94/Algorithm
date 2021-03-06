#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

constexpr int MAX = 100000;
int n;
int res[MAX];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;

	vector<pair<int, int>> in(n);
	vector<pair<int, int>> out(n);

	for (int i = 0; i < n; i++)
	{
		cin >> in[i].first >> out[i].first;
		in[i].second = out[i].second = i;
	}

	sort(in.begin(), in.end());
	sort(out.begin(), out.end());

	priority_queue<int, vector<int>, greater<int>> q;

	int cnt = 0, i = 0, j = 0;

	while (i < n)
	{
		if (in[i].first < out[j].first) {
			if (q.empty()) res[in[i].second] = cnt++;
			else {
				res[in[i].second] = q.top();
				q.pop();
			}
			i++;
		}
		else {
			q.push(res[out[j].second]);
			j++;
		}
	}

	vector<int> ans(cnt);
	for (int i = 0; i < n; i++)
	{
		ans[res[i]]++;
	}
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) cout << ans[i] << " ";

	return 0;
}