#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

/*
   다익스트라 최단경로 구하기
   최소비용과 최소비용까지의 경로를 출력한다.
*/

using namespace std;

constexpr int INF = 987654321;

int n, m, start, ed;
vector<pair<int,int>> mat[1005];
int dist[1005];
int path[1005];
vector<int> v_path;

void dijkstra() {

	priority_queue<pair<int,int>> q;
	q.push({start,0});
	dist[start] = 0;

	while (!q.empty())
	{
		int cur = q.top().first;
		int cost = -q.top().second;
		q.pop();

		for (int i = 0; i < mat[cur].size(); i++)
		{
			int next = mat[cur][i].first;
			int nCost = mat[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				q.push({ next, -dist[next] });
				path[next] = cur;
			}
		}
	}

	cout << dist[ed] << "\n";
	int t = ed;
	while (t)
	{
		v_path.push_back(t);
		t = path[t];
	}
	cout << v_path.size() << "\n";
	for (int i = v_path.size() - 1; i >= 0; i--)
		cout << v_path[i] << " ";

	cout << "\n";

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		int s, e, val;
		cin >> s >> e >> val;
		mat[s].push_back({ e,val });
	}
	cin >> start >> ed;

	dijkstra();

	return 0;
}