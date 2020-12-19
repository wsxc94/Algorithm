#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, m, dir, x, y;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct robot
{
	int x;
	int y;
	int dir;
};
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m));
	vector<vector<bool>> ch(n, vector<bool>(m, false));
	queue<robot> q;

	cin >> x >> y >> dir;
	q.push({ x,y,dir });

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		dir = q.front().dir;
		q.pop();
		if (!ch[x][y]) cnt++;
		ch[x][y] = true;

		bool find = false;

		for (int i = 0; i < 4; i++)
		{	
			int ndir = dir == 0 ? 3 : dir - 1;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!ch[nx][ny] && mat[nx][ny] == 0) {
				q.push({ nx,ny,ndir });
				find = true;
				break;
			}
			// 청소할 공간이 없는경우 방향 회전
			dir = ndir;
		}
		if (find) continue;
		int nx = x - dx[dir];
		int ny = y - dy[dir];
		if (mat[nx][ny]) break; // 네 방향 모두 청소 되있고 뒤가 벽이다.
		q.push({ nx,ny,dir });
	}

	cout << cnt << "\n";
	return 0;
}