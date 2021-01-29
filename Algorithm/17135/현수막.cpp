#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

constexpr int MAX_NUM = 251;
const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int mat[MAX_NUM][MAX_NUM];
bool ch[MAX_NUM][MAX_NUM];
int n, m;

void bfs(int f ,int s) {

	queue<pair<int, int>> q;
	q.push({ f,s });
	ch[f][s] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (!ch[xx][yy] && mat[xx][yy] == 1) {
				q.push({ xx,yy });
				ch[xx][yy] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int cnt = 0;
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
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}