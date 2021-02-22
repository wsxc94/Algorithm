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
   bfs 너비 우선 탐색
   레이저로 연결해야 하는칸 C를 pos에 넣어준후 
   방향이 바뀔 때 마다 +1 카운트를 해주면된다.
*/
constexpr int MAX = 101;

struct point
{
	int x, y, dir, cnt;
};

int n, m;
char mat[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector <pair <int, int>> pos;

int bfs(int st, int ed) {
	memset(dist, -1, sizeof(dist));

	queue<point> q;
	dist[st][ed] = 0;

	for (int i = 0; i < 4; i++) q.push({ st,ed,i,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int direction = q.front().dir;
		int count = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int next_count = count;

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (mat[xx][yy] == '*') continue;
			if (direction != i) next_count = count + 1;
			if (dist[xx][yy] == -1 || dist[xx][yy] >= next_count) {
				dist[xx][yy] = next_count;
				q.push({ xx,yy,i,next_count });
			}
		}
	}
	return dist[pos[1].first][pos[1].second];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'C')
				pos.push_back({ i,j });
		}
	}

	cout << bfs(pos[0].first, pos[0].second) << "\n";

	return 0;
}