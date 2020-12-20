#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
using namespace std;

 struct tomato {
	int x, y, z;
	int cnt;
 };

int m, n, h; //가로 세로 높이
int mat[101][101][101];
bool ch[101][101][101];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
queue<tomato> q;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int cnt = 0;

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {

				cin >> mat[i][j][k];
				if (mat[i][j][k] == 1) {
					q.push({ i, j, k, 0 });
					ch[i][j][k] = true;
				}
				else if (mat[i][j][k] == -1)
					ch[i][j][k] = true;
			}
	if (q.empty()) {
		printf("-1");
		return 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		cnt = max(cnt, cur.cnt);

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];
			
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && !ch[nx][ny][nz]) {
				q.push({ nx, ny, nz, cur.cnt + 1 });
				ch[nx][ny][nz] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < h; k++)
				if (!ch[i][j][k]) {
					printf("-1");
					return 0;
				}

	printf("%d", cnt);
	return 0;

}