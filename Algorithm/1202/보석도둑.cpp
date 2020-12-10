#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

constexpr int MAX_NUM = 300010;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	priority_queue<int> pq;
	vector<pair<int,int>> info(300001);
	vector<int> weight(300001);
	
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> info[i].first >> info[i].second;
	for (int i = 0; i < k; i++)
		cin >> weight[i];

	sort(info.begin(), info.begin() + n);
	sort(weight.begin(), weight.begin() + k);

	long long ans = 0;

	int j = 0;

	for (int i = 0; i < k; i++) {
		while (j < n && info[j].first <= weight[i])
			pq.push(info[j++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans;
	
	
	return 0;
}