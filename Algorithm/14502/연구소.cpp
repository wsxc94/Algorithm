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
   바이러스를 막기위해 벽을 3개 세울수있다 (고정값)
   경우의수 8x8x8 = 4096으로 가능 (dfs , bfs) 사용
   벽을 세운후 바이러스를 퍼트린후 남아있는 0의 개수로 최대값을 구하면 끝이다.
   
   이 문제에서 요구하는 최대 경우의 수가 적어서 브루트포스로 풀 수 있지만
   더 많아질 경우에 대해서 어떻게 풀어야 할지 꼭 생각해봐야겠다.

*/

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, ans = 0;

void bfs(vector<vector<int>>& mat) {
	queue<pair<int, int>> q;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx >= mat.size() || yy >= mat[x].size() || mat[xx][yy] != 0) continue;
			mat[xx][yy] = 2;
			q.push({ xx,yy });
		}
	}

	int cnt = 0;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] == 0) cnt++;
		}
	}

	ans = max(ans, cnt);

}
void dfs(vector<vector<int>> mat, int x, int y, int cnt) {
	mat[x][y] = 1;

	if (cnt == 0) {
		bfs(mat);
		return;
	}
	for (int i = x; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[x].size(); j++)
		{
			if (mat[i][j] == 0) dfs(mat, i, j, cnt - 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m));

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
			if (mat[i][j] == 0) {
				dfs(mat, i, j, 2);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}