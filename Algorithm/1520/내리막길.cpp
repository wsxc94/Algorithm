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
#include <algorithm>

using namespace std;
constexpr int MAX = 500;
int n, m;
int mat[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y) {

	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
		if (mat[xx][yy] < mat[x][y]) {
			dp[x][y] = dp[x][y] + dfs(xx, yy);
		}
	}

	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
			dp[i][j] = -1;
		}
	}

	int path = dfs(0, 0);

	cout << path << "\n";


	return 0;
}