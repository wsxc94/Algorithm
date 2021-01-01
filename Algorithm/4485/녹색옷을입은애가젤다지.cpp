#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
constexpr int MAX_NUM = 130;
constexpr int INF = 987654321;

int n;
int mat[MAX_NUM][MAX_NUM];
int dist[MAX_NUM][MAX_NUM];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int cnt = 0;

	while (true)
	{
		cnt++;

		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				dist[i][j] = INF;
			}
		}

		priority_queue<pair<int, pair<int, int>>> q;
		q.push({ {-mat[0][0]} ,{0,0} });
		dist[0][0] = mat[0][0];

		while (!q.empty())
		{
			int cost = -q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;

				int nCost = cost + mat[xx][yy];
				if (dist[xx][yy] > nCost) {
					dist[xx][yy] = nCost;
					q.push({ {-dist[xx][yy]} ,{xx,yy} });
				}
			}
		}

		cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
	}
	return 0;
}