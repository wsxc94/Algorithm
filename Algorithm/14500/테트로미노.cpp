#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, ans = -987654321;
int mat[501][501];
bool ch[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt, int sum) {

	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy]) continue;

		ch[xx][yy] = true;
		dfs(xx, yy, cnt + 1, sum + mat[xx][yy]);
		ch[xx][yy] = false;
		
	}
}
void shape(int x, int y) {
	int sum = 0;
	//で
	if (x - 1 >= 0 && y + 2 < m) {
		sum = mat[x][y] + mat[x][y + 1] + mat[x][y + 2] + mat[x - 1][y + 1];
		ans = max(ans, sum);
	}
	//た
	if (x + 2 < n && y + 1 < m) {
		sum = mat[x][y] + mat[x + 1][y] + mat[x + 2][y] + mat[x + 1][y + 1];
		ans = max(ans, sum);
	}
	//ぬ
	if (x + 1 < n && y + 2 < m) {
		sum = mat[x][y] + mat[x][y + 1] + mat[x][y + 2] + mat[x + 1][y + 1];
		ans = max(ans, sum);
	}
	//っ
	if (x + 2 < n && y - 1 >= 0) {
		sum = mat[x][y] + mat[x + 1][y] + mat[x + 2][y] + mat[x + 1][y - 1];
		ans = max(ans, sum);
	}
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
			ch[i][j] = true;
			dfs(i, j, 1, mat[i][j]);
			ch[i][j] = false;
			shape(i, j);
		}
	}

	cout << ans << "\n";
	return 0;
}