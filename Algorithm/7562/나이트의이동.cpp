#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;


int dx[] = { -2,-1,1,2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
int dist[302][302];
int mat[302][302];
int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		queue<pair<int, int>> q;
		memset(dist, 0, sizeof(dist));
		memset(mat, 0, sizeof(mat));

		cin >> n;

		int x, y, ex, ey;
		cin >> x >> y >> ex >> ey;

		q.push({ x,y });
		
		while (!q.empty())
		{
			
			x = q.front().first;
			y = q.front().second;
			if (x == ex && y == ey) break;

			q.pop();

			for (int i = 0; i < 8; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || yy < 0 || xx >= n || yy >= n || dist[xx][yy] != 0) continue;
				dist[xx][yy] = dist[x][y] + 1;
				q.push({ xx,yy });
			}
		}

		cout << dist[ex][ey] << "\n";
	}
	return 0;
}