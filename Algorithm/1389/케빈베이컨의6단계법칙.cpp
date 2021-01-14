#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;

vector <int> a[101];
int ch[101], dist[101], ans[101], INF = 987654321;
int n, m, u, v, sum;
void BFS(int v)
{
	queue <int> q;
	q.push(v);
	ch[v] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < a[cur].size(); i++)
		{
			int next = a[cur][i];
			if (ch[next] == 0)
			{
				q.push(next);
				ch[next] = 1;
				dist[next] = dist[cur] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	while (m--)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(ch, 0, sizeof(ch));
		memset(dist, 0, sizeof(dist));
		sum = 0;
		BFS(i);
		for (int j = 1; j <= n; j++)
		{
			sum += dist[j];
		}
		ans[i] = sum;
	}
	for (int i = 1; i <= n; i++)
	{
		if (INF > ans[i])
			INF = ans[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (INF == ans[i])
		{
			cout << i;
			break;
		}

	}
	return 0;
}