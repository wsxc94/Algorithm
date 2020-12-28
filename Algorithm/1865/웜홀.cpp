#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

constexpr int MAX_NUM = 510;
constexpr int INF = 987654321;

int N, M, W;

vector<pair<pair<int, int>, int>> ed;
int dist[MAX_NUM];

void bellmanFord() {
	dist[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < ed.size(); j++)
		{
			int from = ed[j].first.first;
			int to = ed[j].first.second;
			int cost = ed[j].second;

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}
	

	for (int i = 0; i < ed.size(); i++)
	{
		int from = ed[i].first.first;
		int to = ed[i].first.second;
		int cost = ed[i].second;

		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	

	while (t--)
	{
		ed.clear();
		memset(dist, INF, sizeof(dist));
		int a, b, c;

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++)
		{
		   cin >> a >> b >> c;
		   ed.push_back({ {a,b},{c} });
		   ed.push_back({ {b,a},{c} });
		}

		for (int i = 0; i < W; i++)
		{
			cin >> a >> b >> c;
			ed.push_back({ {a,b},{-c} });
		}

		bellmanFord();
	}

	return 0;
}