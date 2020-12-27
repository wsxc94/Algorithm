#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;

constexpr int INF = 987654321;
constexpr int MAX_NUM = 1001;

vector<pair<int,int>> mat[MAX_NUM];
vector<int> dist(MAX_NUM, INF);

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mat[a].push_back({ b,c });
	}
	int start, ed;
	cin >> start >> ed;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({ 0,start });
	dist[start] = 0;
	while (!q.empty())
	{
		int cost = q.top().first;
		int idx = q.top().second;
		q.pop();
		for (int i = 0; i < mat[idx].size(); i++)
		{
			int next = mat[idx][i].first;
			int nCost = mat[idx][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				q.push({ dist[next] , next });
			}
		}
	}

	cout << dist[ed] << "\n";

	return 0;
}