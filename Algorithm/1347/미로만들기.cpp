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

constexpr int MAX = 100;
int n;
bool mat[MAX + 1][MAX + 1];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	string path;
	cin >> path;

	int dir = 0, cx = MAX / 2, cy = MAX / 2;
	int sx = cx, sy = cy, ey = cy, ex = cx;

	mat[cx][cy] = true;

	for (int i = 0; i < n; i++)
	{
		if (path[i] == 'L') dir = (dir + 3) % 4; //왼쪽
		else if (path[i] == 'R') dir = (dir + 1) % 4; //오른쪽
		else if (path[i] == 'F') { // 앞
			cx += dx[dir];
			cy += dy[dir];
			mat[cx][cy] = true;

			if (cx < sx) sx = cx;
			if (cy < sy) sy = cy;
			if (cx > ex) ex = cx;
			if (cy > ey) ey = cy;
		}
	}

	for (int i = sx; i <= ex; i++)
	{
		for (int j = sy; j <= ey; j++)
		{
			if (mat[i][j]) cout << ".";
			else cout << "#";
		}
		cout << "\n";
	}

	return 0;
}