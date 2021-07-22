#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;
/*
    https://www.acmicpc.net/problem/17836
	
	BFS�� �̿��Ͽ� Ž�� ���� ��
	�湮�� ��� �� ���Ⱑ ���� ���� ��� ch[0][][]
	�湮�� ��� �� ���Ⱑ ���� ���� ��� ch[1][][]
	�� ��� �ݺ��ϰ� ���ָ� ã�� �� �ɸ� �ð��� ���
	�׸��� bfs�� ���� �� ���� ã�� ���� �� Fail ���

*/
constexpr int MAX = 101;
struct pos
{
	int x;
	int y;
	int cnt;
	int g;
};
int mat[MAX][MAX];
int ch[2][MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, t, ans;

void bfs() {
	queue<pos> q;
	q.push({ 0, 0, 0, 0 });
	ch[0][0][0] = 1;

	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();

		if (mat[cur.x][cur.y] == 2) cur.g = 1;
		if (cur.x == n - 1 && cur.y == m - 1) {
			ans = cur.cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (cur.g == 1) {
				if (!ch[cur.g][xx][yy]) {
					ch[cur.g][xx][yy] = cur.cnt + 1;
					q.push({ xx,yy,cur.cnt + 1 , cur.g });
				}
			}
			else {
				if (!ch[cur.g][xx][yy] && mat[xx][yy] != 1) {
					ch[0][xx][yy] = cur.cnt + 1;
					q.push({ xx,yy,cur.cnt + 1,cur.g });
				}
			}

		}

	}

}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	bfs();

	if (ans > 0 && ans <= t) cout << ans << '\n';
	else cout << "Fail" << '\n';

	return 0;
}