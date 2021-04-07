#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;
constexpr int MAX = 1001;

queue<pair<int, int> > fire;
queue<pair<int, int> > pos;

int n, h, w, si, sj, ex, ey;

int visit[MAX][MAX];
char ch[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs() {
	pos.push(make_pair(si, sj));
	visit[si][sj] = 1;
	while (!pos.empty()) {
		int fSize = (int)fire.size();
		while (fSize--) {
			//불 먼저 이동
			int xx = fire.front().first;
			int yy = fire.front().second;
			fire.pop();
			for (int k = 0; k < 4; k++) {
				int fnx = xx + dx[k];
				int fny = yy + dy[k];
				if (fnx < 0 || fnx >= h || fny < 0 || fny >= w) continue;
				if (ch[fnx][fny] == '.') {
					ch[fnx][fny] = '*';
					fire.push(make_pair(fnx, fny));
				}
			}
		}
		int posSize = (int)pos.size();
		while (posSize--) {
			// 불 이동 후 상근이 이동
			int x = pos.front().first;
			int y = pos.front().second;
			pos.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					//상근이가 맵의 크기를 벗어났다면 탈출
					cout << visit[x][y] << '\n';
					return;
				}
				if (ch[nx][ny] == '#' || ch[nx][ny] == '*' || visit[nx][ny]) continue;
				pos.push(make_pair(nx, ny));
				visit[nx][ny] = visit[x][y] + 1;
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	while (n--) {
		while (!fire.empty()) fire.pop();
		while (!pos.empty()) pos.pop();
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> ch[i];
			for (int j = 0; j < w; j++) {
				if (ch[i][j] == '@') { // 시작 위치 저장
					si = i, sj = j;
					ch[i][j] = '.';
				}
				else if (ch[i][j] == '*') {
					// fire queue에 불 위치 저장
					fire.push({ i,j });
				}
				else visit[i][j] = 0;
			}
		}
		bfs();
	}
	return 0;
}