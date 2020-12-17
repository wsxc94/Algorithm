#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, dist, cost, des, oil;

struct truck
{
	int dist;
	int oil;

};
struct distCmp
{
	bool operator()(truck& a,truck& b) {
		return a.dist > b.dist;
	}
};
struct oilCmp
{
	bool operator()(truck& a,truck& b) {
		return a.oil < b.oil;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	priority_queue<truck, vector<truck>, distCmp> distQ;
	priority_queue<truck, vector<truck>, oilCmp> oilQ;

	//거리가 가장 가까운 순서대로 넣는다.
	for (int i = 0; i < n; i++)
	{
		cin >> dist >> oil;
		distQ.push({ dist,oil });
	}
	// 마을까지의 거리 , 원래 있던 연료의 양
	cin >> des >> cost;

	truck t;
	int ans = 0;
	while (cost < des)
	{
		while (!distQ.empty() && cost >= distQ.top().dist)
		{
			t.dist = distQ.top().dist;
			t.oil = distQ.top().oil;
			oilQ.push(t);
			distQ.pop();
		}
		if (oilQ.empty()) {
			ans = -1;
			break;
		}
		int res = oilQ.top().oil;
		oilQ.pop();
		cost += res;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}