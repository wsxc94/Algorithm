#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int n;

int mat[101][101];
bool ch[101][101];

int max_num = -1;
int ans = 1;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			max_num = max(max_num, mat[i][j]);
		}
	}
	
	for (int w = 1; w <= max_num; w++)
	{
		int cnt = 0;
		memset(ch, false, sizeof(ch));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!ch[i][j] && mat[i][j] > w) {
					cnt++;
					queue<pair<int, int>> q;
					ch[i][j] = true;
					q.push({ i,j });

					while (!q.empty())
					{
						auto cur = q.front();
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int xx = cur.first + dx[k];
							int yy = cur.second + dy[k];
							if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
							if (!ch[xx][yy] && mat[xx][yy] > w) {
								ch[xx][yy] = true;
								q.push({ xx,yy });
							}
						}
					}
				}
				else {
					ch[i][j] = true;
				}
			}
		}
		ans = max(ans, cnt);
		//cout << ans << "\n";
	}

	cout << ans << "\n";
	return 0;
}