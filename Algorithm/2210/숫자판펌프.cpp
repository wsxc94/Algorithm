#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int mat[5][5];
int ans = 0;
bool ch[1000000];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int sum, int cnt) {
	
	if (cnt == 5) {
		if (!ch[sum]) {
			ch[sum] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= 5 || yy >= 5) continue;
		dfs(xx, yy, sum * 10 + mat[xx][yy], cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, mat[i][j], 0);
		}
	}

	cout << ans << "\n";
	return 0;
}