#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int mat[101][101] = { 0, };
int ch[101][101] = { 0, };

int dx[4] = { -1 ,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m, cnt = 1;

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx > m || yy < 0 || yy > n) continue;

		if (mat[xx][yy] == 1 && ch[xx][yy] == 0) {
			cnt++;
			ch[xx][yy] = 1;
			dfs(xx, yy);
			ch[xx][yy] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{

		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = str[j] - '0';
		}
	}

	dfs(0, 0);

	cout << cnt;

	return 0;
}