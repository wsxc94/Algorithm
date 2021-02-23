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
   z축이 추가된 bfs 탐색 문제. 어렵지않음
*/
constexpr int MAX = 32;

struct point
{
	int x, y, z;
	int time;
};
int l, r, c;
int s_x, s_y, s_z, e_x, e_y, e_z;
char mat[MAX][MAX][MAX];
bool ch[MAX][MAX][MAX];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int bfs() {

	queue<point> q;
	q.push({ s_x,s_y,s_z,0 });
	ch[s_x][s_y][s_z] = true;

	while (!q.empty())
	{
		point cur = q.front();
		q.pop();

		if (cur.x == e_x && cur.y == e_y && cur.z == e_z) return cur.time;

		for (int i = 0; i < 6; i++)
		{
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];
			int zz = cur.z + dz[i];

			if (xx < 0 || yy < 0 || zz < 0 || xx >= l || yy >= r || zz >= c) continue;
			if (mat[xx][yy][zz] == '#') continue;

			if (mat[xx][yy][zz] == '.' && !ch[xx][yy][zz]) {
				ch[xx][yy][zz] = true;
				q.push({ xx,yy,zz,cur.time + 1 });
			}
		}

	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	while (true)
	{

		cin >> l >> r >> c;
		memset(mat, 0, sizeof(mat));
		memset(ch, 0, sizeof(ch));
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> mat[i][j][k];
					if (mat[i][j][k] == 'S') {
						s_x = i;
						s_y = j;
						s_z = k;
					}
					else if (mat[i][j][k] == 'E')
					{
						e_x = i;
						e_y = j;
						e_z = k;
						mat[i][j][k] = '.';
					}
				}
			}
		}

		int res = bfs();

		if (res == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << res << " minute(s)." << endl;

	}
	return 0;
}