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
    최단거리로 이동할 때 제일 먼저 이동할 집하장 경로를 구하는 문제
	플로이드 와샬
	dist 입력값 저장 dist[from][to] = cost , dist[to][from] = cost 양방향
	path 집하장 경로
	1. j에서 k로 갈때 j-i 혹은 i-k 로 갈 수있어서 j-k로 갈수있는 최단거리가 있다면 업데이트한다
	2. path가 INF라면 갱신한다. (path는 최초의 집하장 번호만 저장)
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