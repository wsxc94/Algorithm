#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

constexpr int INF = 987654321;

int cnt, time;

void dijkstra(vector<vector<pair<int, int>>> mat, int start, int n) {
	priority_queue<pair<int, int>> q;
	vector<int> dist(n + 1, INF);

	q.push({ 0,start });
	dist[start] = 0;

	while (!q.empty())
	{
		int cost = -q.top().first;
		int cur = q.top().second;

		q.pop();

		for (auto& m : mat[cur])
		{
			int next = m.first;
			int nCost = m.second + cost;

			if (dist[next] > nCost) {
				dist[next] = nCost;
				q.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != INF) {
			cnt++;
			if (dist[i] > time) time = dist[i];
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int t;

	cin >> t;

	while (t--)
	{
		int n, d, c;
		cin >> n >> d >> c;

		vector<vector<pair<int, int>>> mat(n + 1);

		for (int i = 0; i < d; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			mat[b].push_back({ a,c });
		}
		cnt = 0;
		time = 0;

		dijkstra(mat, c, n);

		cout << cnt << " " << time << "\n";

	}

	return 0;
}