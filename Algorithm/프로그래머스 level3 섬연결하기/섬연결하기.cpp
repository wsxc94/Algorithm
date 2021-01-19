#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

struct Edge {
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c) : v1(a), v2(b), cost(c) {}
	bool operator < (Edge& b) {
		return cost < b.cost;
	}
};

int unf[101];
vector<Edge> ed;

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) unf[a] = b;
	else if (a > b) unf[b] = a;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int answer = 0;
	int n = 4;
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	for (int i = 0; i < n; i++) {
		unf[i] = i;
	}

	for (int i = 0; i < costs.size(); i++) {
		for (int j = 0; j < costs[i].size(); j++) {
			ed.push_back({ costs[i][0] , costs[i][1] , costs[i][2] });
		}
	}

	sort(ed.begin(), ed.end());

	for (int i = 0; i < ed.size(); i++) {

		int a = Find(ed[i].v1);
		int b = Find(ed[i].v2);

		if (a != b) {
			answer += ed[i].cost;
			Union(ed[i].v1, ed[i].v2);
		}

	}

	cout << answer << "\n";
	return 0;
}