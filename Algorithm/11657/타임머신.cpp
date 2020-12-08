#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

constexpr int MAX_NUM = 501;
constexpr int INF = 987654321;
struct Edge
{
	int s;
	int e;
	int val;

	Edge(int _s,int _e,int _val) {
		s = _s;
		e = _e;
		val = _val;
	}
};

int n, m;
vector<Edge> vex;
vector<long long> dist(MAX_NUM, INF);

void BellmanFord() {
	dist[1] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < vex.size(); j++)
		{
			int u = vex[j].s;
			int v = vex[j].e;
			int w = vex[j].val;

			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int j = 0; j < vex.size(); j++)
	{
		int u = vex[j].s;
		int v = vex[j].e;
		int w = vex[j].val;

		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			cout << "-1" << "\n";
			return;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vex.reserve(MAX_NUM);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vex.push_back(Edge(a, b, c));
	}

	BellmanFord();
	
	return 0;
}