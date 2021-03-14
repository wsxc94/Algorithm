#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
/*
   너비우선탐색을 이용하여 해결한 문제
   X좌표 Y좌표 나이트 이동 , 경로의 수 를 큐에 넣어주는식으로 해결
   원숭이는 K번 만큼만 말처럼 이동할 수 있음

*/
constexpr int MAX = 201;

int n, m, k;
int mat[MAX][MAX];
bool ch[MAX][MAX][31];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int knight_dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int knight_dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int BFS() {
	queue<pair<pair<int, int>, pair<int, int>>> que;
	que.push({ { 0, 0 }, { 0,0 } });
	ch[0][0][0] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int knight = que.front().second.first;
		int cnt = que.front().second.second;
		que.pop();

		if (x == n - 1 && y == m - 1) return cnt;
		if (knight < k) {
			for (int i = 0; i < 8; i++) {
				int xx = x + knight_dx[i];
				int yy = y + knight_dy[i];

				if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
				if (mat[xx][yy] == 0 && !ch[xx][yy][knight + 1]) {
					ch[xx][yy][knight + 1] = true;
					que.push({ {xx,yy},{knight+1,cnt+1} });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (mat[xx][yy] == 0 && !ch[xx][yy][knight]) {
				ch[xx][yy][knight] = true;
				que.push({ {xx,yy},{knight , cnt + 1} });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	cout << BFS() << "\n";
	return 0;
}