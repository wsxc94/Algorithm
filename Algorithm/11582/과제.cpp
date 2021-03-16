#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

/*
   하루에 한 과제를 끝낼 수 있고 과제마다 마감일이 있음
   과제를 끌냈을 때 얻을 수 있는 점수의 최댓값을 구하는 문제
*/

int n;

int max_score(vector<pair<int, int>>& v) {
	vector<int> tmp;
	tmp.resize(1001);
	int idx = 0;
	int res = 0;

	while (idx < n)
	{
		for (int i = v[0].first; i > 0 ; i--)
		{
			if (tmp[i] != 0) continue;
			else {
				tmp[i] = v[0].second;
				break;
			}
		}
		idx++;
		v.erase(v.begin());
	}

	for (int i = 0; i <= 1000; i++)
	{
		res += tmp[i];
	}

	return res;

}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	});

	int ans = max_score(v);

	cout << ans << "\n";

	return 0;
}