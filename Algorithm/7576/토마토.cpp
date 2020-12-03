#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int mat[1001][1001] = { 0, };
queue<pair<pair<int, int>,int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, m, cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 1) q.push(make_pair(make_pair(i, j), 0));
		}
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (mat[xx][yy] == 0) {
					mat[xx][yy] = 1;
					q.push(make_pair(make_pair(xx, yy), cnt + 1));
					
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0) {
				cnt = -1;
				break;
			}	
		}
	}

	cout << cnt;
	return 0;
}