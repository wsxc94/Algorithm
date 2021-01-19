#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

char mat[101][101];
bool ch[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
void bfs(int a, int b) {

	queue<pair<int, int>> q;
	q.push({ a,b });
	ch[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= n || ch[xx][yy]) continue;
			if (mat[x][y] == mat[xx][yy]) {
				ch[xx][yy] = true;
				q.push({ xx,yy });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!ch[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	memset(ch, false, sizeof(ch));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 'G') mat[i][j] = 'R';
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!ch[i][j]) {
				bfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt << " " << cnt2 << "\n";



	return 0;
}