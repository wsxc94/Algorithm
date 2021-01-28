#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int mat[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;
int sy, sx, sd;
int ey, ex, ed;
int dist[101][101][4];

struct robot {
	int x, y, dir;
};
int bfs()
{
	queue<robot> q;
	q.push({ sy,sx,sd });
	dist[sy][sx][sd] = 0;

	while (!q.empty()) {

		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;

		q.pop();

		if (x == ey && y == ex && dir == ed) {
			return dist[x][y][dir];
		}

		//현재 방향으로 1,2,3만큼 움직이기
		for (int k = 1; k <= 3; ++k) {
			int xx = x + dy[dir] * k;
			int yy = y + dx[dir] * k;

			if (dist[xx][yy][dir] != -1)continue;

			if (0 <= xx && xx < n && 0 <= yy && yy < m && mat[xx][yy] == 0) {
				dist[xx][yy][dir] = dist[x][y][dir] + 1;
				q.push({ xx,yy,dir });
			}
			else
				break;

		}
		//방향 바꾸기 
		if (dir == 0 || dir == 1) {
			int ndir = 2;
			if (dist[x][y][ndir] == -1) {
				dist[x][y][ndir] = dist[x][y][dir] + 1;
				q.push({ x,y,ndir });
			}
			ndir = 3;
			if (dist[x][y][ndir] == -1) {
				dist[x][y][ndir] = dist[x][y][dir] + 1;
				q.push({ x,y,ndir });
			}
		}
		if (dir == 2 || dir == 3) {
			int ndir = 1;
			if (dist[x][y][ndir] == -1) {
				dist[x][y][ndir] = dist[x][y][dir] + 1;
				q.push({ x,y,ndir });
			}
			ndir = 0;
			if (dist[x][y][ndir] == -1) {
				dist[x][y][ndir] = dist[x][y][dir] + 1;
				q.push({ x,y,ndir });
			}
		}

	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}

	cin >> sy >> sx >> sd >> ey >> ex >> ed;
	sy -= 1; sx -= 1; sd -= 1, ey -= 1; ex -= 1;  ed -= 1;

	cout << bfs() << "\n";

	return 0;
}