#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int mat[101][101];
int air[101][101];
bool ch[101][101];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

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

	int ans = 0;

	while (true)
	{
		memset(ch, false, sizeof(ch));
		memset(air, 0, sizeof(air));

		queue<pair<int, int>> q;
		q.push({ 0,0 });

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (ch[x][y]) continue;
			ch[x][y] = true;

			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
				
				if (mat[xx][yy] == 1) air[xx][yy]++;
				else if (!ch[xx][yy]) q.push({ xx,yy });
			}
		}
		
		bool cmp = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (air[i][j] >= 2) {
					mat[i][j] = 0;
					cmp = true;
				}
			}
		}
		if(cmp) ans++;
		else break;
	}

	cout << ans << "\n";
	
	return 0;
}