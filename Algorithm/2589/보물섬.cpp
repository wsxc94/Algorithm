#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

char mat[50][50];
bool ch[50][50];
int ans = 0;
int n, m;

void bfs(int st, int ed) {
	int path = -1;
	memset(ch, false, sizeof(ch));
	queue<pair<int, int>> q;
	q.push({ st,ed });
	ch[st][ed] = true;

	while (!q.empty())
	{
		int len = q.size();

		for (int i = 0; i < len; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int xx = x + dx[j];
				int yy = y + dy[j];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy] || mat[xx][yy] == 'W') continue;
				q.push({ xx,yy });
				ch[xx][yy] = true;
			}

		}
		path++;
	}

	ans = max(ans, path);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 'L') bfs(i, j);
		}
	}

	cout << ans << "\n";

	return 0;
}