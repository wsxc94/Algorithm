#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int mat[101][101];
bool ch[101][101] = { false, };

int n, m, cnt = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

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

	int before, one = 0;

	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 1) one++;
			}
		}

		if (one == 0) break;
		else {
			cnt++;
			before = one;
			one = 0;
		}

		memset(ch, false, sizeof(ch));

		queue<pair<int, int>> q;
		q.push({ 0, 0 });

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			ch[x][y] = true;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx >= 0 && xx < n && yy >= 0 && yy < m && !ch[xx][yy]) {
					if (mat[xx][yy] == 1) mat[xx][yy] = 0;
					else q.push({ xx,yy });
					ch[xx][yy] = true;
				}
			}
		}	
	}

	cout << cnt << "\n";
	cout << before << "\n";
	return 0;
}