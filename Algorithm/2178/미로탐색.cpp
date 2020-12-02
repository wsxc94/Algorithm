#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int mat[101][101] = { 0, };
int ch[101][101] = { 0, };
int dist[101][101] = { 0, };

int dx[4] = { -1 ,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;

void bfs(int x, int y) {
	ch[x][y] = 1;
	dist[x][y]++;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 || xx < m || yy >= 0 || yy < n) {

				if (mat[xx][yy] == 1 && ch[xx][yy] == 0) {
					ch[xx][yy] = 1;
					q.push({ xx,yy });
					dist[xx][yy] = dist[x][y] + 1;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{

		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[n-1][m-1];

	return 0;
}