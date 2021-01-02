#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

constexpr int MAX_NUM = 301;

int mat[301][301];
bool ch[301][301];

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dist[301][301];

void bfs(int x , int y) {
	
	queue<pair<int, int>> q;
	q.push({ x,y });
	ch[x][y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy] || mat[xx][yy] == 0 ) continue;
			
			ch[xx][yy] = true;
			q.push({ xx,yy });


		}
	}

}
void iceBerg(int x, int y) {

	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || y < 0 || xx >= n || yy >= m) continue;

		if (mat[xx][yy] == 0) {
			cnt++;
		}
	}

	dist[x][y] = cnt;

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

	int year = 0;

	while (true)
	{
		int cnt = 0;

		memset(ch, false, sizeof(ch));
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] != 0 && !ch[i][j]) {
					cnt++;
					bfs(i, j);
				}
			}
		}

		if (cnt >= 2) {
			cout << year << "\n";
			break;
		}
		else if (cnt == 0) {
			cout << 0 << "\n";
			break;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] != 0) {
					iceBerg(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] != 0) {
					mat[i][j] -= dist[i][j];
					if (mat[i][j] < 0) mat[i][j] = 0;
				}
			}
		}

		year++;
	}
	
	return 0;
}