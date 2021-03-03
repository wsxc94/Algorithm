#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

constexpr int MAX = 51, INF = 987654321;
int r, c, start_x, start_y, end_x, end_y, rock_x, rock_y;
int ch[MAX][MAX];
char mat[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> start_q;
queue<pair<int, int>> water_q;

void bfs() {
	int cnt = 0;
	while (!start_q.empty()) {
		cnt++;
		int water_size = water_q.size();

		while (water_size--) {
			int x = water_q.front().first;
			int y = water_q.front().second;

			water_q.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
				if (mat[xx][yy] == 'X' || mat[xx][yy] == 'D' || mat[xx][yy] == '*') continue;
				water_q.push({ xx, yy });
				mat[xx][yy] = '*';
			}
		}

		int start_size = start_q.size();

		while (start_size--) {
			int x = start_q.front().first;
			int y = start_q.front().second;
			start_q.pop();

			ch[x][y] = true;
			if (x == end_x && y == end_y) {
				cout << cnt - 1 << endl;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
				if (mat[xx][yy] == 'X' || mat[xx][yy] == '*' || ch[xx][yy]) continue;
				ch[xx][yy] = true;
				start_q.push({ xx, yy });
			}
		}
	}
	cout << "KAKTUS" << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			cin >> mat[i][j];

			if (mat[i][j] == 'D') {
				end_x = i;
				end_y = j;
			}
			else if (mat[i][j] == 'S')
			{
				start_q.push({ i,j });
			}
			else if (mat[i][j] == '*')
			{
				water_q.push({ i,j });
			}
		}
	}

	bfs();

	return 0;
}