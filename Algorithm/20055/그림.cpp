#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

constexpr int MAX_NUM = 501;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int mat[MAX_NUM][MAX_NUM];
bool ch[MAX_NUM][MAX_NUM];
int cnt, max_ans = 0;
void bfs(int f, int s) {

	int tmp = 0;
	queue<pair<int, int>> q;
	q.push({ f, s });
	ch[f][s] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		tmp++;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy] || mat[xx][yy] != 1) continue;
			q.push({ xx,yy });
			ch[xx][yy] = true;
		}
	}

	if (tmp > max_ans) max_ans = tmp;

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
			if (!ch[i][j] && mat[i][j] == 1) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt << "\n" << max_ans;
	return 0;
}