#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int mat[101][101];
int ch[101][101] = { false, };

int n, m, k, cnt = 0, area = 0;
vector<int> ans;
void bfs(int start , int end) {

	queue<pair<int,int>> q;
	q.push({ start,end });
	ch[start][end] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int xx = dx[i] + x;
			int yy = dy[i] + y;

			if (xx < n && yy < m && xx >= 0 && yy >= 0 && mat[xx][yy] == 0 && !ch[xx][yy]) {
				q.push({ xx, yy });
				ch[xx][yy] = true;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);


	cin >> n >> m >> k;


	int x1, x2, y1, y2;

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				mat[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 0 && !ch[i][j]) {
				bfs(i, j);
				ans.push_back(cnt);
				cnt = 0;
				area++;
			}
		}
		
	}

	sort(ans.begin(), ans.end());
	cout << area << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}


	return 0;
}