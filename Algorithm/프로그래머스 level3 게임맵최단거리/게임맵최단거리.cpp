#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

bool ch[101][101];
int dist[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int answer = 0;

	vector<vector<int>> maps = {
    {1,0,1,1,1},
	{1,0,1,0,1},
	{1,0,1,1,1},
	{1,1,1,0,1},
	{0,0,0,0,1}
	};

	int n = maps.size();
	int m = maps[0].size();

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	ch[0][0] = true;
	dist[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = dx[i] + x;
			int yy = dy[i] + y;

			if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy]) continue;
			if (maps[xx][yy] == 1) {
				ch[xx][yy] = true;
				dist[xx][yy] = dist[x][y] + 1;
				q.push({ xx,yy });
			}

		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}*/
	if (dist[n - 1][m - 1] == 0) cout << -1 << "\n";
	else cout << dist[n - 1][m - 1] << "\n";



	return 0;
}