#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_NUM = 20001;
constexpr int INF = 987654321;

vector<pair<int, int>> vertex[MAX_NUM];
vector<int> dist(MAX_NUM, INF);

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, start;
	cin >> n >> m >> start;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back({ b,c });
	}
	priority_queue<pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
	q.push(make_pair(0, start));
	dist[start] = 0;

	while (!q.empty())
	{
		int cost = q.top().first;
		int idx = q.top().second;
		q.pop();

		for (int i = 0; i < vertex[idx].size(); i++)
		{
			int next = vertex[idx][i].first;
			int nCost = vertex[idx][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				q.push(make_pair(dist[next], next));
			}
		}

	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}