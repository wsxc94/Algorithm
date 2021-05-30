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
   보드에 a~z 까지 26개의 알파벳이 나올 수 있음
   그러므로 check 배열에 26개의 알파벳 '알파벳' -'A' 를 해주면 A = 0 ~ Z = 25 번으로 계산가능
   나머지는 일반적인 깊이우선탐색으로 cnt를 구할 수 있다
*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, ans;

char mat[20][20];
bool check[26];

void dfs(int x , int y , int cnt) {

	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
			if (!check[mat[xx][yy] - 'A']) {
				check[mat[xx][yy] - 'A'] = true;
				dfs(xx, yy, cnt + 1);
				check[mat[xx][yy] - 'A'] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	check[mat[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans << "\n";
	return 0;
}