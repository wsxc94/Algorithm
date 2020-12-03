#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int mat[51][51];
bool ch[51][51];
queue<pair<int, int>> q;

int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { 1,1,1,0,0,-1,-1,-1 };

int n, m, cnt = 0;

void bfs(int x , int y) {
	ch[x][y] = true;

	q.push({ x,y });

	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int xx = tx + dx[i];
			int yy = ty + dy[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (!ch[xx][yy] && mat[xx][yy] == 1) {
					ch[xx][yy] = true;
					q.push({ xx,yy });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		memset(mat, 0, sizeof(mat));
		memset(ch, 0, sizeof(ch));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
			}
		}
	
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!ch[i][j] && mat[i][j] == 1) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;

	}


	return 0;
}