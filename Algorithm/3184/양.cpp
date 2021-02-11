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
constexpr int MAX_NUM = 251;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string mat[252];
bool ch[252][252];
int row, col, ocnt = 0, vcnt = 0;
int oocnt = 0, vvcnt = 0;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) cin >> mat[i];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mat[i][j] != '#' && ch[i][j] == false) {
				ocnt = 0;
				vcnt = 0;
				q.push({ i,j });
				ch[i][j] = 1;
				if (mat[i][j] == 'v') vcnt++;
				else if (mat[i][j] == 'o') ocnt++;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int xx = x + dx[i];
						int yy = y + dy[i];
						if (xx < 0 || xx >= row || yy < 0 || yy >= col) continue;
						if (ch[xx][yy] == true || mat[xx][yy] == '#') continue;
						if (mat[xx][yy] == 'v') vcnt++;
						if (mat[xx][yy] == 'o') ocnt++;
						ch[xx][yy] = 1;
						q.push({ xx,yy });
					}
				}
				if (vcnt >= ocnt) vvcnt += vcnt;
				else oocnt += ocnt;
			}
		}
	}
	cout << oocnt << " " << vvcnt;
	return 0;
}