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
  �ܹ��� �׷��� ���ͽ�Ʈ�� �˰���

  res �迭�� �� ��ȣ�� i -> x �� ����Ÿ��� ������
  x -> �� ��ȣ�� i �� �Ÿ��� ������ �����ش�
  i -> x -> i �� ����Ÿ��� �Ǵ� �Ÿ��� ���̵ȴ�.
*/
constexpr int INF = 987654321;
int N, M, X;
int ans[1001];
int res = 0;
vector<pair<int, int>> edge[1001];
vector<pair<int, int>> goHome[1001];

vector<int> dijkstra(vector<pair<int, int>> ed[1001])
{
	vector<int> dist(1001, INF);
	dist[X] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, X));

	while (!q.empty())
	{
		int cost = -q.top().first;
		int start = q.top().second;
		q.pop();

		if (dist[start] < cost)	continue;

		for (int i = 0; i < ed[start].size(); i++)
		{
			int next_cost = ed[start][i].first + cost;
			int dest = ed[start][i].second;

			if (dist[dest] > next_cost)
			{
				dist[dest] = next_cost;
				q.push(make_pair(-next_cost, dest));
			}
		}
	}

	return dist;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		edge[s].push_back(make_pair(c, d));
		goHome[d].push_back(make_pair(c, s));
	}

	vector<int> forward = dijkstra(edge);
	vector<int> reversed = dijkstra(goHome);

	for (int i = 1; i <= N; i++)
		res = max(res, forward[i] + reversed[i]);

	cout << res << "\n";

	return 0;
}