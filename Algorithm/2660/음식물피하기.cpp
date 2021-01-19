#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int n, m, k, a, b;

bool ch[101][101];
int mat[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int ans = -1;

void bfs(int a , int b) {

	int cnt = 0;

	queue<pair<int, int>> q;
	q.push({ a,b });
	ch[a][b] = true;

	while (!q.empty())
	{
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 1 || yy < 1 || xx > n || yy > m || ch[xx][yy] || mat[xx][yy] != -1) continue;

			q.push({ xx,yy });
			ch[xx][yy] = true;

		}
	}

	if (ans < cnt) ans = cnt;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	while (k--)
	{
		cin >> a >> b;
		mat[a][b] = -1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!ch[i][j] && mat[i][j] == -1) {
				bfs(i,j);
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}