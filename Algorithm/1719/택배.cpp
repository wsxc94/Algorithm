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
#include <algorithm>

using namespace std;
/*
    �ִܰŸ��� �̵��� �� ���� ���� �̵��� ������ ��θ� ���ϴ� ����
	�÷��̵� �ͼ�
	dist �Է°� ���� dist[from][to] = cost , dist[to][from] = cost �����
	path ������ ���
	1. j���� k�� ���� j-i Ȥ�� i-k �� �� ���־ j-k�� �����ִ� �ִܰŸ��� �ִٸ� ������Ʈ�Ѵ�
	2. path�� INF��� �����Ѵ�. (path�� ������ ������ ��ȣ�� ����)
*/
constexpr int INF = 987654321;
int n, m;

void floyd(vector<vector<int>>& dist, vector<vector<int>>& path) {

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (dist[j][i] != INF && dist[i][k] != INF) {
					if (dist[j][k] > dist[j][i] + dist[i][k]) {
						if (path[j][i] != INF) path[j][k] = path[j][i];
						else path[j][k] = i;
					}
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> path(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;

		if (path[a][b] == INF) path[a][b] = b;
		if (path[b][a] == INF) path[b][a] = a;
	}

	floyd(dist , path);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) cout << "- ";
			else if (path[i][j] == INF) cout << "- ";
			else cout << path[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}