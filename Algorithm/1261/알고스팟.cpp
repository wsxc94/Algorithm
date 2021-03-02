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
   최소로 벽 뚫기가 핵심이다.
   벽 = 가중치 로 대입하고 다익스트라 + BFS 를 사용해 문제를 해결했다.
   n,m 위치를 잘봐야 함.
   그리고 입력 자체가 붙어있는 숫자 문자열이기 때문에 이 점도 조심해야한다.

*/
constexpr int INF = 987654321;
int mat[101][101];
int dist[101][101];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dijikstra() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
			if (mat[xx][yy] == 1) {
				if (dist[xx][yy] > dist[x][y] + 1) {
					dist[xx][yy] = dist[x][y] + 1;
					q.push({ xx,yy });
				}
			}
			else if (mat[xx][yy] == 0)
			{
				if (dist[xx][yy] > dist[x][y]) {
					dist[xx][yy] = dist[x][y];
					q.push({ xx,yy });
				}
			}
		}
	}

	cout << dist[m - 1][n - 1] << "\n";

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	string s;

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = s[j] - '0';
			dist[i][j] = INF;
		}
	}

	dijikstra();

	return 0;
}